#include "config.h"

int main(){
    stConfig stconf;
    char path[]="conf.json";
    Config* conf = Config::Instance(path);
    conf->Analytic(&stconf);
    std::cout<<stconf.divWay.type<<stconf.name<<stconf.path<<stconf.sync<<stconf.name<<std::endl;
    return 0;
}
