#ifndef SALT_UTXO_CPP_PAGINATIONDTO_H
#define SALT_UTXO_CPP_PAGINATIONDTO_H

#include "UtxoDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PaginationDto : public oatpp::DTO {
    DTO_INIT(PaginationDto, DTO)

    DTO_FIELD(UInt32, offset);
    DTO_FIELD(UInt32, limit);
    DTO_FIELD(UInt32, count);
    DTO_FIELD(Vector<T>, items);
};

class UtxoPageDto : public PaginationDto<oatpp::Object<UtxoDto>> {
    DTO_INIT(UtxoPageDto, PaginationDto<oatpp::Object<UtxoDto>>)
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_PAGINATIONDTO_H
