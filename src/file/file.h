#ifndef _INCLUDE_FILE_H_
#define _INCLUDE_FILE_H_

#include <stdio.h>
#include <iostream>
#include <stdlib.h>  
#include <string.h>
#include <stdarg.h>  
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h> 

class FileOprImp{
    public:
        virtual int Write(std::string buf)=0;
        virtual void Close()=0;
        virtual int Open(std::string strPath,std::string strFileName)=0;
        virtual int Size()=0;
        virtual int ReName(std::string newFileName)=0;
        // virtual int Sync()=0;
};

class  FileOpr:public FileOprImp{
    public:
        FileOpr();
        ~FileOpr();
    public:
        int Write(std::string buf);
        void Close();
        int Open(std::string strPath,std::string strFileName);
        int Size();
        int ReName(std::string newFileName);

    private:
        std::string createDir(std::string strDir);
        int reopen();
        void destory();
    private:
        std::string m_strPath; 
        std::string m_strFileName;
        FILE* m_pFileOpr;
        int m_iSize;
};
#endif 
