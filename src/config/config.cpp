
#include "config.h"
    
Config::Config(std::string path):path(path){
}
Config::~Config(){
}
Config& Config::operator=(const Config& conf){
}

int Config::Analytic(stConfig *config){
    Json::Reader reader;  
    Json::Value root; 
    std::ifstream in(path.c_str(), std::ios::binary);
    if( !in.is_open()  )   {   
        std::cout << "Error opening file \n";   
        return -1;   
    }
    if(reader.parse(in,root)){
        config->level = LEVEL(root["level"].asInt());
        config->sync = root["sync"].asBool();
        config->divWay.type = int(root["divSize"].asBool());
        if (config->divWay.type) {
            config->divWay.divMessage.time.interval = root["divWay"]["size"].asInt();
        }else{
            config->divWay.divMessage.size.size = root["divWay"]["time"].asInt();
        }
        config->name = root["name"].asString(); 
        config->path = root["path"].asString(); 
        return 0;
    }
    std::cout<<"Error reading file \n";   
    return -1;
}
std::shared_ptr<Config> Config::Instance(const std::string path)
{
    if (!m_pInstance){
        MyLock lock(Config::m_lock);
        if (!m_pInstance)
            m_pInstance= std::shared_ptr<Config>(new Config(path)); 
    }
    return m_pInstance;
}
pthread_mutex_t*  Config::m_lock = new pthread_mutex_t ;
std::shared_ptr<Config> Config::m_pInstance = NULL;
