#ifndef _FMT_H_
#define _FMT_H_

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <time.h>
#include <stdarg.h>
#include "common.h"

std::string NowTime();
std::string NowDate();
std::string Level(int type);
std::string Char(const char *msg);

std::string Int(int msg);

std::string String(std::string msg);

std::string  Long(long msg);

std::string Addr(long msg);

#endif
