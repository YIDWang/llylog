#include "log.h"

void print(Logger log){
    log.Debug("%d %s",3,"hello");
    log.Debug("%d %s",4,"hello");
    log.Debug("%d %s",7,"hello");

    log.Info("%d %s",3,"hello");
    log.Info("%d %s",2,"hello");
    log.Info("%d %s",4,"hello");

    log.Error("%d %s",1,"hello");
    log.Error("%d %s",2,"hello");
    log.Error("%d %s",3,"hello");
    log.Error("%d %s",4,"hello");

    log.Fatal("%d %s",1,"hello");
}
void test(){
    Logger log;
    log.Init("conf.json");
    print(log);
}

void test_one(){
    Logger log;
    log.Init("conf_one.json");

    log.Debug("%d %s",3,"hello");

    log.Info("%d %s",1,"hello");
    log.Info("%d %s",3,"hello");
    sleep(1);
    log.Info("%d %s",2,"hello");
    log.Info("%d %s",4,"hello");
}
void test_two(){
    Logger log;
    log.Init("conf_two.json");
    for(int i = 0 ; i < 1024 ; i ++)
        log.Info("%d %s",i,"hello");
}
void test_three(){
    Logger log;
    log.Init("conf_three.json");

}
int main(){
    test_two();
    return 0;
}
