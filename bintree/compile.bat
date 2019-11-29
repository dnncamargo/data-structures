ECHO "============COMPILING PROCESS============"
gcc -c bintree.c
gcc -c main.c
gcc -o main main.c bintree.c
