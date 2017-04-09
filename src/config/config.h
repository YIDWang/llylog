
#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <json/json.h>
#include "../common.h"
#include "../lock.h"
#include <fstream>

class Config{
public:
    int Analytic(const std::string path,stConfig *config);
    static std::shared_ptr<Config> Instance();
    ~Config();
private:
    Config();
    Config& operator=(const Config&);
    Config(const Config&);
    class CGarbo  {  
        public:
            ~CGarbo(){
                if(Config::m_pInstance) {
                    Config::m_pInstance.reset();  
                } 
                if (Config::m_lock){
                    delete m_lock;
                    m_lock = NULL;
                }
            }  
    };  
private:
    static std::shared_ptr<Config> m_pInstance;
    static pthread_mutex_t*  m_lock;
    static CGarbo Garbo;  //定义一个静态成员变量，程序结束时，系统会自动调用它的析构
    // std::string path;
};

#endif
