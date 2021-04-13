#ifndef SALT_UTXO_CPP_DATABASECOMPONENT_H
#define SALT_UTXO_CPP_DATABASECOMPONENT_H

#include "dto/ConfigDto.h"
#include "db/UtxoDb.h"

class DatabaseComponent {
public:

    /**
     * Create database client
     */
    OATPP_CREATE_COMPONENT(std::shared_ptr<UtxoDb>, utxoDb)([] {
        OATPP_COMPONENT(oatpp::Object<ConfigDto>, config); // Get config component

        /* Create database-specific ConnectionProvider */
        auto connectionProvider = std::make_shared<oatpp::postgresql::ConnectionProvider>(config->dbConnectionString);

        /* Create database-specific ConnectionPool */
        auto connectionPool = oatpp::postgresql::ConnectionPool::createShared(connectionProvider,
                                                                              10 /* max-connections */,
                                                                              std::chrono::seconds(
                                                                                      5) /* connection TTL */);
        /* Create database-specific Executor */
        auto executor = std::make_shared<oatpp::postgresql::Executor>(connectionPool);

        /* Create MyClient database client */
        return std::make_shared<UtxoDb>(executor);
    }());
};

#endif //SALT_UTXO_CPP_DATABASECOMPONENT_H
