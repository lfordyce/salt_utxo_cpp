#ifndef SALT_UTXO_CPP_UTXOCONTROLLER_H
#define SALT_UTXO_CPP_UTXOCONTROLLER_H

#include "service/UtxoService.h"

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

/**
 * Utxo REST controller.
 */
class UtxoController : public oatpp::web::server::api::ApiController {
public:
    UtxoController(const std::shared_ptr<ObjectMapper> &objectMapper)
            : oatpp::web::server::api::ApiController(objectMapper) {}

private:
    UtxoService m_utxoService;
public:
    static std::shared_ptr<UtxoController> createShared(
            OATPP_COMPONENT(std::shared_ptr<ObjectMapper>,
                            objectMapper) // Inject objectMapper component here as default parameter
    ) {
        return std::make_shared<UtxoController>(objectMapper);
    }

    ENDPOINT("GET", "api/v1/records/offset/{offset}/limit/{limit}", getUtxoRecordds,
             PATH(UInt32, offset),
             PATH(UInt32, limit)) {
        OATPP_LOGI("Records", "offset=%d limit=%d", *offset.get(), *limit.get());
        return createDtoResponse(Status::CODE_200, m_utxoService.findAllRecords(offset, limit));
    }

    ENDPOINT("GET", "api/v1/addrs", getAddresses) {
        OATPP_LOGI("Get all distinct addresses", "");
        return createDtoResponse(Status::CODE_200, m_utxoService.findAddressAll());
    }

    ENDPOINT("GET", "api/v1/addrs/{address}", getBalanceByAddress,
             PATH(String, address, "address"),
             QUERY(Boolean, spent, "unspentOnly")) {
        OATPP_LOGI("Balance", "address=%s", address->getData());
        return createDtoResponse(Status::CODE_200, m_utxoService.findBalanceByAddress(address, spent));
    }
};

#include OATPP_CODEGEN_BEGIN(ApiController)

#endif //SALT_UTXO_CPP_UTXOCONTROLLER_H
