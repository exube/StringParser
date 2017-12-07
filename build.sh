#!/bin/sh

cd $(dirname $0)
cd StringParser

make clean
make all

cd ..

if [ ! -d bin ]
then
  mkdir bin
fi

cp StringParser/*.so bin/

if [ ! -d include ]
then
  mkdir include
fi

cp StringParser/*.h include/
