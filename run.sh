#!/bin/bash

PROJECT_NAME="daru"
BUILD_DIR_NAME="cmake-build-debug"

PATH_NAME=$(cd "$(dirname "$0")" && pwd)
cd $PATH_NAME

FILE_NAME="CMakeLists.txt"
if ! test -e $FILE_NAME
then
touch CMakeLists.txt
touch main.cpp
echo "#include <iostream>
using namespace std;

int main() {
	cout << \"Hello World!\" << endl;
}" > main.cpp
echo "cmake_minimum_required(VERSION 3.9)
project($PROJECT_NAME)

set(CMAKE_CXX_STANDARD 11)

add_executable($PROJECT_NAME main.cpp)" > CMakeLists.txt
cmake -H. -B$BUILD_DIR_NAME -DCMAKE_BUILD_TYPE=Debug -G "CodeBlocks - Unix Makefiles"
# cmake --build $BUILD-DIR-NAME -- -j3
echo ""
else
cmake --build $PATH_NAME/$BUILD_DIR_NAME --target daru -- -j 2
if [ $? -eq 0 ]
then
$BUILD_DIR_NAME/$PROJECT_NAME
echo ""
else
echo -e ""
fi
fi