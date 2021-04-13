#ifndef SALT_UTXO_CPP_BALANCEDTO_H
#define SALT_UTXO_CPP_BALANCEDTO_H

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class BalanceDto : public oatpp::DTO {
    DTO_INIT(BalanceDto, DTO)

    DTO_FIELD(String, balance);

    DTO_FIELD(Int64, tx_count);
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_BALANCEDTO_H
