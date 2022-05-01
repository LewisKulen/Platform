#! /bin/bash

BIN_PATH='/home/fgh/Project/Platform/server/bin'
cat ${BIN_PATH}/pid | while read line
do 
    echo ${line}
done

TEST_PATH='/home/fgh/Project'
cat ${TEST_PATH}/pid | while read line
do 
    echo 'kill -9 '${line}
    kill -9 ${line}
done
