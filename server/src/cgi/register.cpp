#include <cstdlib>

#include "../db/MySqlQuery.h"
#include "fcgi_config.h"
#include "fcgi_stdio.h"

enum REGISTER_RET_CODE
{
	RRT_NULL = 0
	RRT_SVR_ERROR,
	RRT_REPEAT,
	RRT_SUCCESS,
};

int main()
{
	int count = 0;
	while(FCGI_Accept() >= 0)
	{
		printf("Content-type: text/html\r\n"
				"\r\n"
				"<title>Hello World</title>"
				"<h1>Hello World from FastCGI!</h1>"
				"Request number is: %d\n",
				++count);
	
	
		int len = atoi(getenv("CONTENT_LENGTH"));
		
		MySQLConnection mySqlCon;
		bool flag = mySqlCon.Connect("127.0.0.1",3306,"fgh","xxxx","Platform");

		if(flag)
			printf("connect db success!");
		else
			printf("connect db failed!");

		MySQLQuery query(&mySqlCon, "SELECT * FROM tab_user where id = " + );
		if(query.ExecuteQuery())
		{
			
			unsigned int row = query.GetResultRowCount();
			if(row)	// repeat
			{
				printf("result=%d,")
			}
		}	
		mySqlCon.Disconnect();
		// MySQLQuery updateQuery(&mySqlCon, "...");
		// updateQuery.ExecuteUpdate();

		// MySQLQuery deleteQuery(&mySqlCon,"...")
		// deleteQuery.ExecuteDelete();

		// MySQLQuery insertQuery(&mySqlCon,"...")
		// insertQuery.ExecuteInsert();

	}
	return 0;
}

