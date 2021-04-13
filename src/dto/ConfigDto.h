#ifndef SALT_UTXO_CPP_CONFIGDTO_H
#define SALT_UTXO_CPP_CONFIGDTO_H

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class ConfigDto : public oatpp::DTO {
    DTO_INIT(ConfigDto, DTO)

    DTO_FIELD(String, host);

    DTO_FIELD(UInt16, port);

    DTO_FIELD(String, dbConnectionString);
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_CONFIGDTO_H
