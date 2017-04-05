
#ifndef _CONFIG_H_
#define _CONFIG_H_
#include <stdio.h>
#include <iostream>
#include <json/json.h>
#include "common.h"
#include <fstream>
class Config{
public:
    Config(char *path);
    int Analytic(stConfig *config);
private:
    char *path;
};
#endif
