

#include"stack.h"
void push(stack_t *stack, int element){
    if (stack -> size == maxsize)
        exit(-1);
    stack -> mas[stack -> size] = element;
    stack -> size++;
}
int pop(stack_t *stack){
    int t;
    if (stack -> size == 0)
        exit(-1);
    stack -> size--;
    t = stack -> mas[stack -> size];
    stack -> mas[stack -> size] = 0;
    return t;
}
void add(stack_t *stack){
    int e1, e2;
    e1 = pop(stack);
    e2 = pop(stack);
    e1 = e1 + e2;
    push(stack, e1);
}
void sub(stack_t *stack){
    int e1, e2;
    e1 = pop(stack);
    e2 = pop(stack);
    e1 = e2 - e1;
    push(stack, e1);
}
void mul(stack_t *stack){
    int e1, e2;
    e1 = pop(stack);
    e2 = pop(stack);
    e1 = e1 * e2;
    push(stack, e1);
}
void divi(stack_t *stack){
    int e1, e2;
    e1 = pop(stack);
    e2 = pop(stack);
    e1 = e2 / e1;
    push(stack, e1);
}
void zermas(int *stack_a){
    int i;
    for (i = 0; i < maxsize; i++)
        stack_a[i] = 0;
}
void stack_ctor(stack_t *stack){
    int i;
    stack -> size = 0;
    for(i = 0; i <  maxsize; i++)
        stack -> mas[i] = 0;
}
void inf_ctor(struct inf *textin){
    int i;
    textin -> sd = 0;
    for(i = 0; i < sz; i++){
        textin -> operation[i] = 0;
    }
}
FILE* File1_ctor(FILE *mf){
    mf =  fopen("steck.txt", "w");
    return mf;
}
FILE* File2_ctor(FILE *getin){
    getin =  fopen("firstst.txt", "r");
    return getin;
    }
FILE* File3_ctor(FILE *disa){
    disa =  fopen("disa.txt", "w");
    return disa;
}
void File_dtor(FILE *mf){
    fclose(mf);
}
void dump(stack_t *stack, FILE *mf){
    int i;
   if (err(mf) == -1)
        exit(1);
    for (i = 0; i < stack -> size; i++)
        fprintf(mf, "%d\n", stack -> mas[i]);
}
int err(FILE *mf){
    if (mf == NULL)
        return -1;
        return 0;
}
