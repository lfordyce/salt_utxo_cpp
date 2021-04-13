#ifndef SALT_UTXO_CPP_BOOTSTRAPCOMPONENT_H
#define SALT_UTXO_CPP_BOOTSTRAPCOMPONENT_H

#include "dto/ConfigDto.h"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/core/base/CommandLineArguments.hpp"

#include <cstdlib>

class BootstropComponent {
private:
    oatpp::base::CommandLineArguments m_cmdArgs;
public:
    BootstropComponent(const oatpp::base::CommandLineArguments &cmdArgs)
            : m_cmdArgs(cmdArgs) {}

public:
    OATPP_CREATE_COMPONENT(oatpp::Object<ConfigDto>, config)([this] {
        const char *configPath = CONFIG_PATH;
        auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

        oatpp::String configText = oatpp::base::StrBuffer::loadFromFile(configPath);

        if (configText) {
            auto profiles = objectMapper->readFromString<oatpp::Fields<oatpp::Object<ConfigDto>>>(configText);

            const char *profileArg = std::getenv("CONFIG_PROFILE"); // first read from env variable
            if (profileArg == nullptr) {
                // if no env variables get from command line
                profileArg = m_cmdArgs.getNamedArgumentValue("--profile", "dev");
            }

            OATPP_LOGD("Server", "Loading configuration profile '%s'", profileArg);
            auto profile = profiles.getValueByKey(profileArg, nullptr);
            if (!profile) {
                throw std::runtime_error("No configuration profile found. Server won't run.");
            }
            return profile;
        }
        OATPP_LOGE("BootstropComponent", "Can't load configuration file at path '%s'", configPath);
        throw std::runtime_error("[AppComponent]: Can't load configuration file");
    }());
};

#endif //SALT_UTXO_CPP_BOOTSTRAPCOMPONENT_H
