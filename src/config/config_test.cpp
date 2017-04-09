#include "config.h"

int main(){
    stConfig stconf;
    std::string path="conf.json";
    std::shared_ptr<Config> conf = Config::Instance();
    conf->Analytic(path,&stconf);
    std::cout<<stconf.divWay.type<<stconf.name<<stconf.path<<stconf.sync<<stconf.name<<std::endl;
    return 0;
}
