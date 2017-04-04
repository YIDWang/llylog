#ifndef _COMMON_H_
#define _COMMON_H_

#define MAX_BUF 1024
enum LEVEL{
    EUNM_LEVEL_NULL = 0,
    ENUM_LEVEL_DEBUG = 1,
    ENUM_LEVEL_INFO = 2,
    EUNM_LEVEL_ERROR = 3,
    ENUM_LEVEL_FATAL = 4
};
enum DIVWAY{
    ENUM_DIVWAY_NULL = 0,
    ENUM_DIVWAY_TIME = 1,
    EUNM_DIVWAY_SIZE = 2
};
union DIV{
    struct stTimeWay{
       int second; 
    };
    struct stSizeWay{
        int size;
    };
};
struct stConfig{
    LEVEL level ;//默认的打印级别           
    bool sync ; //同步异步
    DIVWAY divWay ;//文件切割方式
    DIV divMessage ;//切割的信息
    char name[MAX_BUF]; //输出文件名字
    char path[MAX_BUF]; //输出文件的路径
};
#endif 
