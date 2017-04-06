#include "log.h"
#include "fmt.h"

Logger::Logger(){

}

int Logger::Init(char *path){
    Config* conf = Config::Instance(path);
    if (conf == NULL)
        return -1;
    if (0 != conf->Analytic(&m_stConf))
        return -1;
    return 0; 
}
//时间+文件+行号+信息+自定义信息
void Logger::debug(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){
    char buf[MAX_BUF];
    std::string msg;
    int size;
    va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
    va_start (vArgList, fmt); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
    size = vsnprintf(buf, MAX_BUF, fmt, vArgList); //注意,不要漏掉前面的_
    va_end(vArgList); //用va_end宏结束可变参数的获取
    msg = dealString(fileName,functionName,line,buf); 
    std::cout<<msg;
}
void Logger::info(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){

}
void Logger::error(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){

}
void Logger::fatal(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){

}

std::string Logger::getNowTime(){
    time_t tNow =time(NULL);
    tm* ptm = localtime(&tNow);
    char szTmp[MAX_BUF] = {0};
    strftime(szTmp,MAX_BUF,"%F %H:%M:%S",ptm); 
    return szTmp;
}

std::string Logger::dealString(const char* fileName,const char* functionName,unsigned int line,const char* fmt){
   std::string msg;
   msg = "[fileName:"+Char(fileName) + "] [function:" + Char(functionName) +"] [line:" + Int(line) + "] [msg:"+ Char(fmt)+"]\n";
   return msg;
}
