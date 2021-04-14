### API:
* Get balance for address:
```
curl 'http://0.0.0.0:7000/api/v1/addrs/{address}?unspentOnly=true'
curl 'http://0.0.0.0:7000/api/v1/addrs/33iCT4LNevPgBzkHXZNHNLiBRMmWijGpbu?unspentOnly=false'
```
* Get all unique addresses:
```
curl 'http://0.0.0.0:7000/api/v1/addrs'
```
* Get pagination of records:
```
curl 'http://0.0.0.0:7000/api/v1/records/offset/0/limit/10'
```