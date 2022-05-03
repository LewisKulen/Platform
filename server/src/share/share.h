#ifndef __SHARE_H__
#define __SHARE_H__

enum RET_CODE_NUM
{
    RCN_NULL = 0,
    
    RCN_REGISTER_BEGIN = 1,
    RCNR_RCV_ERR,
    RCNR_DB_ERR,
    RCNR_ID_REPEAT,
    RCNR_SUCCESS,

    RCN_LOGIN_BEGIN = 10,
    

    RCN_UPDATE_BEGIN = 20,
};

#include <string>
#include <ctime>

std::string getLocalFmtTime();

#endif

