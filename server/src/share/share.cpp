#include "share.h"



std::string getLocalFmtTime()
{
    std::time_t t = std::time(nullptr);
    char kTime[100] = {0};
    if (std::strftime(kTime, sizeof(kTime), "%Y-%m-%d %H:%M:%S", std::localtime(&t))) {
        return std::string(kTime);
    }
    return "";
}

