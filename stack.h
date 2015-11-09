
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define maxsize 20
#define sz 5
typedef struct {
    int mas[maxsize];
    int size ;
}stack_t;
struct inf{
    char operation[sz];
    int sd;
};
enum{
#define DEF_CMD(name, num) num,
#include"ASA.h"
#undef DEF_CMD
};
void push(stack_t *stack, int element);
int pop(stack_t *stack);
void add(stack_t *stack);
void sub(stack_t *stack);
void mul(stack_t *stack);
void divi(stack_t *stack);
void zermas(int *stack_a);
void stack_ctor(stack_t *stack);
void inf_ctor(struct inf *textin);
FILE* File1_ctor(FILE *mf);
FILE* File2_ctor(FILE *getin);
FILE* File3_ctor(FILE *disa);
void File_dtor(FILE *mf);
void dump(stack_t *stack, FILE *mf);
int err(FILE *mf);
