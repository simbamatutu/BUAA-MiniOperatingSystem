#!/bin/bash

awk 'NR==8 || NR==32 || NR==128 || NR==512 || NR==1024' file>hello_os.c_1
