#ifndef _LOG_H_
#define _LOG_H_

#include <time.h>
#include <stdarg.h>
#include "common.h"
#include "config.h"
#include "fmt.h"



class Log{
public:
    #define Debug(fmt, args...) debug(__FILE__,__FUNCTION__, __LINE__, fmt, ##args)
    #define Info(fmt, args...)  info(__FILE__,__FUNCTION__, __LINE__, fmt, ##args)
    #define Error(fmt, args...) error(__FILE__,__FUNCTION__, __LINE__, fmt, ##args)
    #define Fatal(fmt, args...) fatal(__FILE__,__FUNCTION__, __LINE__, fmt, ##args)
    virtual void debug(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...)=0;
    virtual void info(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...)=0;
    virtual void error(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...)=0;
    virtual void fatal(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...)=0;
};

class Logger:public Log{
public:
    Logger();
    int Init(char *path);
    virtual void debug(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...);
    virtual void info(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...);
    virtual void error(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...);
    virtual void fatal(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...);
private:
    std::string getNowTime();
    std::string dealString(const char* fileName,const char* functionName,unsigned int line,const char* fmt);
private:
    // std::string m_pConfigPath;
    stConfig m_stConf;
};
#endif 
