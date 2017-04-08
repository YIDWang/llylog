#include "log.h"

int main(){
    Logger log;
    log.Init("conf.json");
    log.Debug("%d %s",1,"hello");
    log.Debug("%d %s",2,"hello");
    log.Debug("%d %s",3,"hello");
    log.Debug("%d %s",4,"hello");
    log.Debug("%d %s",5,"hello");
    log.Debug("%d %s",7,"hello");



    log.Info("%d %s",1,"hello");
    log.Info("%d %s",2,"hello");
    log.Info("%d %s",3,"hello");
    log.Info("%d %s",4,"hello");
    log.Info("%d %s",5,"hello");
    log.Info("%d %s",7,"hello");


    log.Error("%d %s",1,"hello");
    log.Error("%d %s",2,"hello");
    log.Error("%d %s",3,"hello");
    log.Error("%d %s",4,"hello");
    log.Error("%d %s",5,"hello");
    log.Error("%d %s",7,"hello");

    log.Fatal("%d %s",1,"hello");
    return 0;
}
