#include <iostream>
# compile: $ g++ colorterm.c -o colorterm
const char *def = "\x1b[39;49m"; 
const char *reset = "\x1b[0m";

const char *red = "\x1b[31m";
const char *green = "\x1b[32m";
const char *yellow = "\x1b[33m";
const char *cyan = "\x1b[36m";

const char *bold = "\b;1m";

const char *boldred = "\x1b[31;1m";


int main()
{
    std::cout << red << "Hello world";
    std::cout << yellow << "Yellow";
    std::cout << cyan << "Cyan bold";
    std::cout << boldred << "default";

    return 0;
}