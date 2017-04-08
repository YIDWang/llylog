#include "fmt.h"

std::string Char(const char *msg){
    return msg;    
}

std::string Int(int msg){
    std::stringstream ss;
    ss<<msg;
    return ss.str();
}

std::string String(std::string msg){
    return msg;
}

std::string  Long(long msg){
    std::stringstream ss;
    ss<<msg;
    return ss.str();
}

std::string Addr(long msg){
    std::stringstream ss;
    ss<<msg;
    return ss.str();
}

std::string NowTime(){
    time_t tNow =time(NULL);
    tm* ptm = localtime(&tNow);
    char szTmp[MAX_BUF] = {0};
    strftime(szTmp,MAX_BUF,"%F %H:%M:%S",ptm); 
    return szTmp;
}
std::string NowDate(){
    time_t tNow = time(NULL);
    tm* ptm = localtime(&tNow);
    char szTmp[MAX_BUF] = {0};
    strftime(szTmp,MAX_BUF,"%F",ptm); 
    return szTmp;
}
std::string Level(int type){
    switch (type){
        case 1:
            return "Debug";
        case 2:
            return "Info";
        case 3:
            return "Error";
        case 4:
            return "Fatal";
    }
}
