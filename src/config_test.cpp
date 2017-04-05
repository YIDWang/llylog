#include "config.h"

int main(){
    stConfig stconf;
    char path[]="conf.json";
    Config conf(path);
    conf.Analytic(&stconf);
    std::cout<<stconf.divMessage.time.time<<stconf.name<<stconf.path<<stconf.sync<<stconf.name<<std::endl;
    return 0;
}
