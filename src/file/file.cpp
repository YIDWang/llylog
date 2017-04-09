#include "file.h"

FileOpr::FileOpr():m_pFileOpr(NULL),m_iSize(0){

}
FileOpr::~FileOpr(){
    destory();
}
int FileOpr::ReName(std::string newFileName){
    if(m_pFileOpr != NULL){
        fclose(m_pFileOpr);
        m_pFileOpr = NULL;
    }
    std::string strTemp = m_strPath + newFileName;
    if(rename(m_strFileName.c_str(),strTemp.c_str()) != 0){
        return -1;
    }
    reopen();
    return 0;
}
//////////////////////////////////////////////////////////
int FileOpr::Write(std::string buf){
    int size = fwrite(buf.c_str(),sizeof(char),buf.length(),m_pFileOpr);
    if (size == 0){
        return -1;
    }
    m_iSize += size;
    return 0;
}
void FileOpr::Close(){
    destory();
}

int FileOpr::Open(std::string strPath,std::string strFileName){
    destory();
    m_strPath = createDir(strPath);
    if (m_strPath == ""){
       return -1; 
    }
    m_strFileName = m_strPath + strFileName;
    // std::cout<<strTemp<<std::endl;
    m_pFileOpr = fopen(m_strFileName.c_str(),"w");
    if(m_pFileOpr == NULL){
        return -1;
    }
    return 0;
}
int FileOpr::Size(){
    unsigned long filesize = -1;      
    struct stat statbuff;  
    if(stat(m_strFileName.c_str(), &statbuff) < 0){  
        return filesize;  
    }else{  
        filesize = statbuff.st_size;  
    }  
    return filesize;
}

int FileOpr::reopen(){
    m_pFileOpr = fopen(m_strFileName.c_str(),"w");
    if(m_pFileOpr == NULL){
        return -1;
    }
    return 0;
}
/////////////////////////////////////////////////////////////////
std::string FileOpr::createDir(std::string strDir){
    int iLength = strDir.length();
    if (strDir.at(iLength-1) != '/' && strDir.at(iLength-1)!= '\\' ){
        strDir += "/";
    }
    std::string strSuber ;
    int index = strDir.find_first_of('/');
    int sumIndex = 0;
    while ( index != std::string::npos){
        strSuber.assign(strDir,0,index);
        if (access(strSuber.c_str(),F_OK) != 0){
            if(mkdir(strSuber.c_str(),0755)!= 0){
                return "";
            }
        }
        // std::cout<<strSuber<<std::endl;
        index = strDir.find_first_of('/',index+1);
    }
    return strDir;
}

void FileOpr::destory(){
    if(m_pFileOpr != NULL){
        fclose(m_pFileOpr);
        m_pFileOpr = NULL;
    }
}
