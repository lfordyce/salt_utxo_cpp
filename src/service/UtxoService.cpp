#include "UtxoService.h"

oatpp::Object<PageDto<oatpp::Object<UtxoDto>>>
UtxoService::findAllRecords(const oatpp::UInt32 &offset, const oatpp::UInt32 &limit) {

    oatpp::UInt32 countToFetch = limit;

    if(limit > 10) {
        countToFetch = 10;
    }
    auto dbResult = m_database->findAllRecords(offset, countToFetch);
    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());

    auto items = dbResult->fetch<oatpp::Vector<oatpp::Object<UtxoDto>>>();

    auto page = PageDto<oatpp::Object<UtxoDto>>::createShared();
    page->offset = offset;
    page->limit = countToFetch;
    page->count = items->size();
    page->items = items;

    return page;
}

oatpp::Object<BalanceDto> UtxoService::findBalanceByAddress(const oatpp::String &address, const oatpp::Boolean &spent) {
    auto dbResult = m_database->findBalanceByAddress(address, spent);

    OATPP_ASSERT_HTTP(dbResult->isSuccess(), Status::CODE_500, dbResult->getErrorMessage());
    OATPP_ASSERT_HTTP(dbResult->hasMoreToFetch(), Status::CODE_404, "Balance not found");

    auto result = dbResult->fetch<oatpp::Vector<oatpp::Object<BalanceDto>>>();
    OATPP_ASSERT_HTTP(result->size() == 1, Status::CODE_500, "Unknown error");

    return result[0];
}
