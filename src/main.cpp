#include "controller/UtxoController.h"
#include "BootstrapComponent.h"
#include "DatabaseComponent.h"
#include "ServiceComponent.h"

#include "oatpp/network/Server.hpp"

#include <iostream>

void run(const oatpp::base::CommandLineArguments &args) {
    BootstropComponent bootstropComponent(args);
    ServiceComponent serviceComponent;
    DatabaseComponent databaseComponent;

    /* create ApiControllers and add endpoints to router */
    auto router = serviceComponent.httpRouter.getObject();
    auto utxoController = UtxoController::createShared();
    utxoController->addEndpointsToRouter(router);

    oatpp::network::Server server(serviceComponent.serverConnectionProvider.getObject(),
                                  serviceComponent.serverConnectionHandler.getObject());

    OATPP_LOGI("Server", "Running on port %s...",
               serviceComponent.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());
    server.run();
}

int main(int argc, const char *argv[]) {
    oatpp::base::Environment::init();

    run(oatpp::base::CommandLineArguments(argc, argv));

    oatpp::base::Environment::destroy();

    return 0;
}