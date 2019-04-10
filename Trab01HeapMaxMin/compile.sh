#!/bin/bash
echo "============COMPILING PROCESS============"
gcc -c prio.c
gcc -c main.c
gcc -o main main.c prio.c
