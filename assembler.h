#define sz 5
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct inf{
    char operation[sz];
    int sd;
};
enum{
#define DEF_CMD(name, num) num,
#include"ASA.h"
#undef DEF_CMD
};
