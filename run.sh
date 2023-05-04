#!/bin/bash

rm -r build/ bin/
mkdir build

if [ "$(expr substr $(uname -s) 1 10)" == "MINGW64_NT" ];then
    cd build && cmake ..  -G "MinGW Makefiles" && make
# elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ];then
else
    cd build && cmake .. && make
fi

cd ..

# echo "***************************"
echo " Finish build this project "
# echo "***************************"
