
#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <json/json.h>
#include "common.h"
#include "lock.h"
#include <fstream>

class Config{
public:
    int Analytic(stConfig *config);
    static Config* Instance(char *path);
    ~Config();
private:
    Config(char *path);
    Config& operator=(const Config&);
    Config(const Config&);
    class CGarbo  {  
        public:
            ~CGarbo(){
                if(Config::instance) {
                    delete Config::instance;  
                    Config::instance = NULL;
                } 
                if (Config::m_lock){
                    delete Config::m_lock;
                    Config::m_lock == NULL;
                }
            }  
    };  
private:
    static Config* instance;
    static pthread_mutex_t*  m_lock;
    static CGarbo Garbo;  //定义一个静态成员变量，程序结束时，系统会自动调用它的析构
    char *path;
};

#endif
