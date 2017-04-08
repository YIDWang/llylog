g++  -c -I ./ config.cpp  -o config.o 
g++  -c -I ./ file.cpp -o file.o
g++  -c -I ./ file_manage.cpp -o file_manage.o  
g++  -c -I ./ fmt.cpp  -o fmt.o 
g++  -c -I ./ log.cpp  -o log.o 
g++  -c -I ./ log_test.cpp -o log_test.o  
g++  log_test.o config.o fmt.o log.o file_manage.o file.o  -ljson -o ./test/log_test
#./config_test
rm *.o
