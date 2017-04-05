g++  -c -I ./ config.cpp  -o config.o 
g++  -c -I ./ config_test.cpp -o config_test.o  
g++  config_test.o config.o -ljson -o config_test
#./config_test
rm *.o
