#ifndef SALT_UTXO_CPP_UTXODB_H
#define SALT_UTXO_CPP_UTXODB_H

#include "dto/UtxoDto.h"
#include "oatpp-postgresql/orm.hpp"

#include OATPP_CODEGEN_BEGIN(DbClient)

class UtxoDb : public oatpp::orm::DbClient {
public:
    UtxoDb(const std::shared_ptr<oatpp::orm::Executor> &executor)
            : oatpp::orm::DbClient(executor) {}

    QUERY(findAllRecords,
          "SELECT CAST(id as varchar), txid, address, CAST(amount as varchar), spent FROM btc_utxo LIMIT :limit OFFSET :offset;",
          PREPARE(true),
          PARAM(oatpp::UInt32, offset),
          PARAM(oatpp::UInt32, limit))

    QUERY(findBalanceByAddress,
          "SELECT CAST(sum(amount) as varchar) as balance, count(txid) AS tx_count FROM public.btc_utxo WHERE address =:address AND spent=:spent",
          PREPARE(true),
          PARAM(oatpp::String, address),
          PARAM(oatpp::Boolean, spent))
};

#include OATPP_CODEGEN_END(DbClient)

#endif //SALT_UTXO_CPP_UTXODB_H
