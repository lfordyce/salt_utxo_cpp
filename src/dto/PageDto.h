#ifndef SALT_UTXO_CPP_PAGEDTO_H
#define SALT_UTXO_CPP_PAGEDTO_H

#include "UtxoDto.h"

#include OATPP_CODEGEN_BEGIN(DTO)

template<class T>
class PageDto : public oatpp::DTO {
    DTO_INIT(PageDto, DTO)

    DTO_FIELD(UInt32, offset);
    DTO_FIELD(UInt32, limit);
    DTO_FIELD(UInt32, count);
    DTO_FIELD(Vector<T>, items);
};

class UtxoPageDto : public PageDto<oatpp::Object<UtxoDto>> {
    DTO_INIT(UtxoPageDto, PageDto<oatpp::Object<UtxoDto>>)
};

#include OATPP_CODEGEN_END(DTO)

#endif //SALT_UTXO_CPP_PAGEDTO_H
