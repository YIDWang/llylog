#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <iostream>
#include <cstdlib>                                                                                                                                                                      
#include <memory>
#include "fmt.h"

#define MAX_BUF 1024
#define DEBUG 1
#define INFO 2
#define ERROR 3
#define FATAL 4

enum LEVEL{
    EUNM_LEVEL_NULL = 0,
    ENUM_LEVEL_DEBUG = 1,
    ENUM_LEVEL_INFO = 2,
    ENUM_LEVEL_ERROR = 3,
    ENUM_LEVEL_FATAL = 4
};
enum DIVWAY{
    ENUM_DIVWAY_TIME = 0,
    EUNM_DIVWAY_SIZE = 1
};
struct stTimeWay{
    int interval; 
    time_t  divTime; 
};
struct stSizeWay{
    int size;
};

union DIV{
    stTimeWay time;
    stSizeWay size;
};

//0-----------time
//1-----------size
struct stDiv{
    int type; 
    DIV divMessage;
};

struct stConfig{
    LEVEL level ;//默认的打印级别           
    bool sync ; //同步异步
    stDiv divWay ;//文件切割方式
    std::string name; //输出文件名字
    std::string  path; //输出文件的路径
};

#endif 
