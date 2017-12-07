#!/bin/sh

cd $(dirname $0)
cd StringParser

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
