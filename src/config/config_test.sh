g++  -c -I ./ config.cpp -std=c++11  -o config.o 
g++  -c -I ./ config_test.cpp -std=c++11 -o config_test.o  
#g++  config_test.o config.o -std=c++11 -ljson  -o config_test
g++  config_test.o config.o -std=c++11 -ljson -o ../test/config_test
#./config_test
rm *.o
