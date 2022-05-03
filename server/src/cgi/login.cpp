#include <cstdlib>
#include <ctime>

#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/value.h>

#include "../db/MySqlQuery.h"
#include "../share/share.h"

#include "fcgi_config.h"
#include "fcgi_stdio.h"


int main()
{
	while(FCGI_Accept() >= 0)
	{
		char* contentLength = getenv("CONTENT_LENGTH");
		int len;
		if (contentLength != NULL) {
            len = strtol(contentLength, NULL, 10);
        }
        else {
            len = 0;
        }

		printf("Content-type: text/html\r\n\r\n");

		int ret_cod = RCN_LOGIN_BEGIN;
		
		if(len > 0)
		{
			std::string jsonStr;
            for (int i = 0; i < len; i++) 
			{
				char ch ;
                if ((ch = getchar()) < 0) 
				{
					ret_cod = RCNL_RCV_ERR;
                    break;
				}
                jsonStr.push_back(ch);
            }

			if(ret_cod != RCNL_RCV_ERR)
			{
				Json::Reader reader;
				Json::Value request;
				reader.parse(jsonStr,request);	// parse jsonStr to request

				MySQLConnection mySqlCon;
				bool flag = mySqlCon.Connect("127.0.0.1",3306,"fgh","xxxx","Platform"); // should in config file

				if(flag)
				{
					std::string queryStr = "SELECT * FROM tab_user where user_id = " + request["user_id"].asString();
					MySQLQuery query(&mySqlCon,queryStr);
					if(query.ExecuteQuery())
					{
						unsigned int row = query.GetResultRowCount();
						if(row <= 0)
						{
							ret_cod = RCNL_ID_MISS;
						}
					}

					if(ret_cod == RCN_LOGIN_BEGIN)	// pass all prev check
					{
				

					
					}
					mySqlCon.Disconnect();
				}
				else
				{
					ret_cod = RCNL_DB_ERR;
				}
			}
        }
		else
		{
			ret_cod = RCNL_RCV_ERR;
		}

		Json::Value kJson;
		kJson["ret_cod"] = ret_cod;
		printf("%s",kJson.toStyledString().c_str());

	}
	return 0;
}

