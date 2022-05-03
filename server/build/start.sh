#! /bin/bash
BIN_PATH='/home/fgh/Project/Platform/server/bin'
CGI_PATH='/home/fgh/Project/Platform/server/src/cgi'
DB_PATH='/home/fgh/Project/Platform/server/src/db'
SHARE_PATH='/home/fgh/Project/Platform/server/src/share'

# test 9999
# login 10000
# register 10001
# update 10002

# g++ $(CGI_PATH)/login.cpp $(DB_PATH)/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o $(BIN_PATH)/login.cgi
g++ ${CGI_PATH}/register.cpp ${DB_PATH}/MySqlQuery.cpp ${SHARE_PATH}/share.cpp -lfcgi -ljsoncpp -I/usr/include/mysql -lmysqlclient -o ${BIN_PATH}/register.cgi
spawn-fcgi -a 127.0.0.1 -p 10001 -P ${BIN_PATH}/pid -f ${BIN_PATH}/register.cgi

# g++ $(CGI_PATH)/update.cpp $(DB_PATH)/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o $(BIN_PATH)/update.cgi


