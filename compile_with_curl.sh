#!/bin/bash

export CFLAGS="-O3"

wget http://curl.haxx.se/download/curl-7.34.0.tar.bz2
tar xjf curl-7.34.0.tar.bz2
cd curl-7.34.0
mkdir /tmp/curl
./configure --prefix=/tmp/curl
make -j install

cd ..
./autogen.sh
./configure --with-libcurl=/tmp/curl CFLAGS="-O3"
make -j

echo "Execute manualmente rm -rf curl-7.34.0 /tmp/curl"
