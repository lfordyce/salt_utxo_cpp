#ifndef SALT_UTXO_CPP_UTXODTO_H
#define SALT_UTXO_CPP_UTXODTO_H

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "oatpp-postgresql/Types.hpp"


#include OATPP_CODEGEN_BEGIN(DTO)


class UtxoDto : public oatpp::DTO {

    DTO_INIT(UtxoDto, DTO)

    DTO_FIELD(String, id);
    DTO_FIELD(String, txid);
    DTO_FIELD(String, address);
    DTO_FIELD(String, amount);
    DTO_FIELD(Boolean, spent);
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_UTXODTO_H
