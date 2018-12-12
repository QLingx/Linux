#!/bin/bash

ids=$1
IFS=","
for id in $ids;do
    echo 'nihao '$id''
    # curl -d '[{"id":'$id',"audit_status":"approved","reason":""}]' '127.0.0.1:8011/api/postaudit/mod'
    sleep 1;
done
