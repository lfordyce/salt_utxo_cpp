#ifndef SALT_UTXO_CPP_UTXOSERVICE_H
#define SALT_UTXO_CPP_UTXOSERVICE_H

#include "db/UtxoDb.h"
#include "dto/StatusDto.h"
#include "dto/PaginationDto.h"
#include "dto/BalanceDto.h"

#include "oatpp/web/protocol/http/Http.hpp"
#include "oatpp/core/macro/component.hpp"

class UtxoService {
private:
    typedef oatpp::web::protocol::http::Status Status;
private:
    OATPP_COMPONENT(std::shared_ptr<UtxoDb>, m_database); // Inject database component
public:
    oatpp::Object<PaginationDto<oatpp::Object<UtxoDto>>> findAllRecords(const oatpp::UInt32& offset, const oatpp::UInt32& limit);
    oatpp::Object<BalanceDto> findBalanceByAddress(const oatpp::String& address, const oatpp::Boolean& spent);
};

#endif //SALT_UTXO_CPP_UTXOSERVICE_H
