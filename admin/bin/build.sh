#!/bin/sh

c++ -I'/usr/include/mysql/' -L'/usr/lib64/mysql/' -lmysqlclient_r -I'/usr/local/include/' -L'/usr/local/lib64/' in.avaya.cpp -o in.avaya.o