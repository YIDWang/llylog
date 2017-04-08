#ifndef _FILE_MANAGE_H_
#define _FILE_MANAGE_H_
#include <map>
#include "file.h"
#include "../common.h"

class FileManageImp{
    public:
        virtual int Operater(int type,std::string msg) = 0;
};

class FileManage:public FileManageImp{
    public:
        FileManage(stDiv *div,std::string path,std::string name);
        ~FileManage();
    public:
        int Operater(int type,std::string msg);
    private:
        int checkFile(int type);
        int wirte(int type,std::string msg);
        int reOpen(int type);
        int open(int type);
    private:
        typedef std::map<int, FileOprImp*> MAP_FILE;
        MAP_FILE  m_mapFilePool;
        typedef std::map<int, stDiv*> MAP_DIV;
        MAP_DIV  m_mapMes;
        std::string m_strPath;
        std::string m_strFileName;
};
#endif 
