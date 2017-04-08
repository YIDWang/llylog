g++  -c -I ./ file.cpp  -o file.o 
g++  -c -I ./ file_test.cpp -o file_test.o  
g++  file_test.o file.o -ljson -o ../test/file_test
#./file_test
rm *.o
