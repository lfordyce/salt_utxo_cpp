#ifndef SALT_UTXO_CPP_ADDRESS_H
#define SALT_UTXO_CPP_ADDRESS_H

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class AddressDto : public oatpp::DTO {
    DTO_INIT(AddressDto, DTO)
    DTO_FIELD(String, address);
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_ADDRESS_H
