#include "file_manage.h"

FileManage::FileManage(stDiv *div,std::string path,std::string name){
    m_strPath = path;
    m_strFileName = name;
   for (int i = 0 ; i < 4 ; i++){
        m_mapFilePool[i+1] = new FileOpr();
        m_mapMes[i+1] = new stDiv();
        m_mapMes[i+1]-> type = div->type;
        m_mapMes[i+1]-> divMessage = div->divMessage;
        open(i+1);
   }
}

FileManage::~FileManage(){
    MAP_FILE::iterator it;
    for(it = m_mapFilePool.begin(); it != m_mapFilePool.end() ; it++){
        delete it->second;
        it->second == NULL;
    }
    m_mapFilePool.clear();

    MAP_DIV::iterator itMes;
    for(itMes = m_mapMes.begin(); itMes != m_mapMes.end() ; itMes++){
        delete itMes->second;
        itMes->second == NULL;
    }
    m_mapMes.clear();

}

int FileManage::Operater(int type,std::string msg){
    if(wirte(type,msg) !=0){
        return -1;
    }
    return 0;
}

int FileManage::checkFile(int type){
    FileOprImp *file = m_mapFilePool[type];
    switch (m_mapMes[type]->type){
        case 1:{
                    int size = file->Size();
                    if(m_mapMes[type]->divMessage.size.size <= size){
                        return reOpen(type);
                    }
                    break;
               }
        case 0:{
                    time_t start = m_mapMes[type]->divMessage.time.divTime;
                    time_t end = time(NULL);
                    unsigned long interval = m_mapMes[type]->divMessage.time.interval;
                    if (difftime(end,start) >= interval){
                        return reOpen(type);
                    }
                    break;
               }
    } 
    return 0;
} 

int FileManage::wirte(int type,std::string msg){
    return m_mapFilePool[type]->Write(msg);
}

int FileManage::open(int type){
    // std::string timeTemp =  NowTime();
    std::string strNewFileName = m_strFileName+ "-"  + Level(type);
    if(m_mapFilePool[type]->Open(m_strPath,strNewFileName) !=0){
        return -1;
    }
    if(m_mapMes[type]->type){
        m_mapMes[type]->divMessage.time.divTime = time(NULL);
    }
    return 0;
} 


int FileManage::reOpen(int type){
    std::string time =  NowTime();
    std::string strNewFileName = m_strFileName + time + Level(type);
    FileOprImp *file = m_mapFilePool[type];
    file->Close();
    if(file->ReName(strNewFileName)!= 0){
        return -1;
    }
    if(file->Open()!=0){
        return -1;
    }
    return 0;
}
