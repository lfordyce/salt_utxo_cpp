#cmake_minimum_required(VERSION 3.16)
cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME salt_utxo_cpp)

project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 11)

add_library(${PROJECT_NAME}-lib
        src/BootstrapComponent.h
        src/DatabaseComponent.h
        src/ErrorHandler.h
        src/ErrorHandler.cpp
        src/ServiceComponent.h
        src/dto/StatusDto.h
        src/dto/ConfigDto.h
        src/dto/UtxoDto.h
        src/dto/PaginationDto.h
        src/dto/BalanceDto.h
        src/db/UtxoDb.h
        src/controller/UtxoController.h
        src/service/UtxoService.h
        src/service/UtxoService.cpp src/dto/Address.h)

target_include_directories(${PROJECT_NAME}-lib PUBLIC src)

## link libs
find_package(oatpp              1.2.5 REQUIRED)
find_package(oatpp-postgresql   1.2.5 REQUIRED)

target_link_libraries(${PROJECT_NAME}-lib
        PUBLIC oatpp::oatpp
        PUBLIC oatpp::oatpp-test
        PUBLIC oatpp::oatpp-postgresql
)

add_definitions(
        # Path to config file #
        -DCONFIG_PATH="${CMAKE_CURRENT_LIST_DIR}/resources/config.json"
)

#################################################################
## add executables
add_executable(${PROJECT_NAME}-exe src/main.cpp)
target_link_libraries(${PROJECT_NAME}-exe ${PROJECT_NAME}-lib)
add_dependencies(${PROJECT_NAME}-exe ${PROJECT_NAME}-lib)

add_executable(${PROJECT_NAME}-test test/tests.cpp)
target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME}-lib)
add_dependencies(${PROJECT_NAME}-test ${PROJECT_NAME}-lib)

enable_testing()
add_test(project-tests ${PROJECT_NAME}-test)