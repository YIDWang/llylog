#include "file.h"

int main(){
    FileOpr file;
    file.Open("index/file/opr","file");
    file.Write("index");
    file.Write("index");
    file.Write("index");
    file.Write("index");
    file.Write("index");
    file.Close();
    return 0;
}
