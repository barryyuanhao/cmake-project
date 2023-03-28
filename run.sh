#!/bin/bash

rm -r build/ bin/
mkdir build
cd build && cmake .. && make
cd ..

# echo "***************************"
echo " Finish build this project "
# echo "***************************"

# bin/node_one

# bin/node_two