# SALT UTXO C++

C++ implementation of the SALT Engineering Backend Technical Challenge.

### Features

- Solution is implemented as an HTTP server using [Oat++](https://oatpp.io/) as the web framework.
- PostgreSQL is used to host the BTC UTXO data for efficient query capabilities.
- Multiple REST routes to satisfy both balance retrieval and additional data insights.

### Install & Execution

#### Prerequisites
- Git
- Docker
- Docker Compose

#### Run
- Clone the repository.
```shell
git clone https://github.com/lfordyce/salt_utxo_cpp.git && cd salt_utxo_cpp
```
- Docker compose execution.
```shell
docker-compose -f docker-compose.yaml up
```

### API:
- Get the balance by providing the BTC address and balance type (spent/unspent).
```shell
curl 'http://0.0.0.0:7000/api/v1/addrs/{address}?unspentOnly=true'
# example:
curl 'http://0.0.0.0:7000/api/v1/addrs/33iCT4LNevPgBzkHXZNHNLiBRMmWijGpbu?unspentOnly=false'
```
- Get all unique BTC addresses within data set.
```shell
curl 'http://0.0.0.0:7000/api/v1/addrs'
```
- Get pagination result set of the BTC UTXO data.
```shell
curl 'http://0.0.0.0:7000/api/v1/records/offset/{offset}/limit/{limit}'
# example
curl 'http://0.0.0.0:7000/api/v1/records/offset/0/limit/10'
```