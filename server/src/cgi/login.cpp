#include <cstdlib>

#include "./Platform/server/src/db/MySqlQuery.h"
#include "fcgi_config.h"
#include "fcgi_stdio.h"


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

		MySQLConnection mySqlCon;
		bool flag = mySqlCon.Connect("127.0.0.1",3306,"fgh","xxxx","Platform");

		if(flag)
			printf("connect db success!");
		else
			printf("connect db failed!");

		MySQLQuery query(&mySqlCon, "SELECT * FROM tab_company;");
		if(query.ExecuteQuery())
		{
			
			unsigned int row = query.GetResultRowCount();
			unsigned int col = query.GetFieldCount();
			for (unsigned int r = 0; r < row; ++r)
			{
				printf("%s | %s | %s | %s | %s | %s | %s | %s",
				query.getString(r+1,"Co_id").c_str(),
				query.getString(r+1,"Co_name").c_str(),
				query.getString(r+1,"Co_tel").c_str(),
				query.getString(r+1,"Co_address").c_str(),
				query.getString(r+1,"Co_posX").c_str(),
				query.getString(r+1,"Co_posY").c_str(),
				query.getString(r+1,"Co_createTime").c_str(),
				query.getString(r+1,"Co_updateTime").c_str());
				
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

