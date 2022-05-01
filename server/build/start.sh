#! /bin/bash
BIN_PATH='/home/fgh/Project/Platform/server/bin'
CGI_PATH='/home/fgh/Project/Platform/server/src/cgi'
DB_PATH='/home/fgh/Project/Platform/server/src/db'

# g++ $(CGI_PATH)/login.cpp $(DB_PATH)/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o $(BIN_PATH)/login.cgi
# g++ $(CGI_PATH)/register.cpp $(DB_PATH)/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o $(BIN_PATH)/register.cgi
# g++ $(CGI_PATH)/update.cpp $(DB_PATH)/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o $(BIN_PATH)/update.cgi



TEST_PATH='/home/fgh/Project'
g++ ${TEST_PATH}/test.cpp ${DB_PATH}/MySqlQuery.cpp -lfcgi -I/usr/include/mysql -lmysqlclient -o ${TEST_PATH}/test.cgi
spawn-fcgi -a 127.0.0.1 -p 9999 -P ${TEST_PATH}/pid -f ${TEST_PATH}/test.cgi

