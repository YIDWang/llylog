#include <fstream>
#include <sys/mman.h>
#include<ctime>
#include <fcntl.h>
#include <iostream>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
using namespace std;
#define MAX_BUF (4*1024)

void fstream_test(char *buf){
    ofstream f;
    f.open("fstream.txt");      
    int start = clock();
    for(int i=0 ; i <100000 ; i++)
        f<<buf;
    int end = clock();
    cout<<"time:"<<(end-start)<<endl;
    f.close();               

}
void fopen_test(char *buf){
    FILE *f;
    f = fopen("fopen.txt","wb");
    int start = clock();
    for(int i=0 ; i <100000 ; i++)
        fwrite(buf,sizeof(char),MAX_BUF,f);
    int end = clock();
    cout<<"time:"<<(end-start)<<endl;
    fclose(f);
}

void open_test(char *buf){
    int f;
    f = open("open.txt",O_WRONLY,664);
    int start = clock();
    for(int i=0 ; i <100000 ; i++)
        write(f,buf,MAX_BUF);
    int end = clock();
    cout<<"time:"<<(end-start)<<endl;
    close(f);

}

int main()
{
    char buf[MAX_BUF];
    memset(buf,'1',MAX_BUF);
    // for(int i=0 ; i <100000 ; i++)
        fstream_test(buf);
        cout<<"------------------------------"<<endl;
    // for(int i=0 ; i <100000 ; i++)
        fopen_test(buf);
        cout<<"------------------------------"<<endl;
    // for(int i=0 ; i <100000 ; i++)
        open_test(buf);
        cout<<"------------------------------"<<endl;
    return 0;
}

