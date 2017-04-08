g++  -c -I ./ file.cpp  -o file.o 
g++  -c -I ./ file_manage.cpp -o file_manage.o  
#g++  file_manage.o file.o -ljson -o file_test
#./file_test
rm *.o
