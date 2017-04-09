#include "log.h"


Logger::Logger(){

}

Logger::~Logger(){
    destory();
}
int Logger::Init(const std::string path){
    std::shared_ptr<Config> conf = Config::Instance();
    if (conf == NULL)
        return -1;
    if (0 != conf->Analytic(path,&m_stConf))
        return -1;
    m_pFile = std::shared_ptr<FileManage>(new FileManage(&m_stConf.divWay,m_stConf.path,m_stConf.name));
    return 0; 
}
void Logger::Destory(){
    destory();
}
//时间+文件+行号+信息+自定义信息
void Logger::debug(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){
    if (m_stConf.level > ENUM_LEVEL_DEBUG){
        return; 
    }
    char buf[MAX_BUF];
    std::string msg;
    int size;
    va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
    va_start (vArgList, fmt); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
    size = vsnprintf(buf, MAX_BUF, fmt, vArgList); //注意,不要漏掉前面的_
    va_end(vArgList); //用va_end宏结束可变参数的获取
    msg = dealString(fileName,functionName,line,buf); 
    if (m_stConf.sync){
        m_pFile->Operater(DEBUG,msg);
    }else{

    }
}
void Logger::info(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){
    if(m_stConf.level >  ENUM_LEVEL_INFO){
        return;
    }
    char buf[MAX_BUF];
    std::string msg;
    int size;
    va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
    va_start (vArgList, fmt); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
    size = vsnprintf(buf, MAX_BUF, fmt, vArgList); //注意,不要漏掉前面的_
    va_end(vArgList); //用va_end宏结束可变参数的获取
    msg = dealString(fileName,functionName,line,buf); 
    if (m_stConf.sync){
        m_pFile->Operater(INFO,msg);
    }else{

    }
}

void Logger::error(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){
    if (m_stConf.level > ENUM_LEVEL_ERROR){
        return ;
    }
    char buf[MAX_BUF];
    std::string msg;
    int size;
    va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
    va_start (vArgList, fmt); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
    size = vsnprintf(buf, MAX_BUF, fmt, vArgList); //注意,不要漏掉前面的_
    va_end(vArgList); //用va_end宏结束可变参数的获取
    msg = dealString(fileName,functionName,line,buf); 
    if (m_stConf.sync){
        m_pFile->Operater(ERROR,msg);
    }else{

    }
}

void Logger::fatal(const char* fileName,const char* functionName,unsigned int line,const char* fmt,...){
    char buf[MAX_BUF];
    std::string msg;
    int size;
    va_list vArgList; //定义一个va_list型的变量,这个变量是指向参数的指针.
    va_start (vArgList, fmt); //用va_start宏初始化变量,这个宏的第二个参数是第一个可变参数的前一个参 //数,是一个固定的参数.
    size = vsnprintf(buf, MAX_BUF, fmt, vArgList); //注意,不要漏掉前面的_
    va_end(vArgList); //用va_end宏结束可变参数的获取
    msg = dealString(fileName,functionName,line,buf); 
    m_pFile->Operater(FATAL,msg);
    exit(1); 
}


std::string Logger::dealString(const char* fileName,const char* functionName,unsigned int line,const char* fmt){
   std::string msg;
   msg = "[fileName:" + Char(fileName) + "] [function:" + Char(functionName) +"] [line:" + Int(line) + "] [msg:"+ Char(fmt)+"]\n";
   return msg;
}

void Logger::destory(){
}
