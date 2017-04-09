g++  -c -I ./ ../config/config.cpp -std=c++11 -o config.o 
g++  -c -I ./ ../file/file.cpp -std=c++11 -o file.o
g++  -c -I ./ ../file/file_manage.cpp -std=c++11 -o file_manage.o  
g++  -c -I ./ ../fmt.cpp  -o fmt.o 
g++  -c -I ./ log.cpp  -std=c++11 -o log.o 
g++  -c -I ./ log_test.cpp -std=c++11 -o log_test.o  
g++  log_test.o config.o fmt.o log.o file_manage.o file.o  -ljson -o ../test/log_test
#./config_test
rm *.o
