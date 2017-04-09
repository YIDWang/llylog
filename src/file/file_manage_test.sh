g++  -c -I ./ file.cpp   -std=c++11 -o file.o 
g++  -c -I ./ file_manage.cpp  -std=c++11 -o file_manage.o  
#g++  file_manage.o file.o -ljson -o file_test
#./file_test
rm *.o
