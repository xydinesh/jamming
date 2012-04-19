#!/bin/bash
set -e
for i in $(find . -maxdepth 1 -name '*.cpp'  -mmin -20)
do
echo "compiling $i"
echo " "
echo "***********************************"
g++ $i -o $(echo $i|sed 's/.cpp/ /g');
if [ "$1" > "0" ]
then
    echo "run $(echo $i|sed 's/.cpp/ /g')"
    echo " "
    echo "***********************************"
    ./$(echo $i|sed 's/.cpp/ /g')
    echo "***********************************"
    echo " "
fi

if [ "$1" = "clean" ]
then
    echo "clean ./$(echo $i|sed 's/.cpp/ /g')"
    rm ./$(echo $i|sed 's/.cpp/ /g')
    echo "***********************************"
    echo " "
    echo " "
fi
done
