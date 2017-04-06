#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <iostream>
#include <cstdlib>                                                                                                                                                                      

#define MAX_BUF 1024
enum LEVEL{
    EUNM_LEVEL_NULL = 0,
    ENUM_LEVEL_DEBUG = 1,
    ENUM_LEVEL_INFO = 2,
    EUNM_LEVEL_ERROR = 3,
    ENUM_LEVEL_FATAL = 4
};
enum DIVWAY{
    ENUM_DIVWAY_TIME = 0,
    EUNM_DIVWAY_SIZE = 1
};
struct stTimeWay{
    int time; 
};
struct stSizeWay{
    int size;
};

union DIV{
    stTimeWay time;
    stSizeWay size;
};

struct stConfig{
    LEVEL level ;//默认的打印级别           
    bool sync ; //同步异步
    bool divWay ;//文件切割方式
    DIV divMessage ;//切割的信息
    std::string name; //输出文件名字
    std::string  path; //输出文件的路径
};
#endif 
