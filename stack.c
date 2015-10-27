#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define maxsize 20
typedef struct {
    int mas[maxsize];
    int size;
}stack_t;
struct inf{
    char operation[5];//операция
    int sd;//число
};
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
void dump(stack_t *stack, FILE *mf){
    int i;
    err(mf);
    for (i = 0; i < stack -> size; i++)
        fprintf(mf, "%d\n", stack -> mas[i]);
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
void err(FILE *mf){
    if (mf == NULL)
        exit(-1);
}
void assembler(FILE *getin, int *stack_a, stack_t *stack,struct inf *textin){
    int k, i = 0;
    while (fscanf (getin, "%s%d", textin -> operation, &(textin -> sd)) != EOF) {
            if (strcmp(textin -> operation, "push") == 0){
                stack_a[i++] = 1;
                push(stack, textin -> sd);
                stack_a[i++] = textin -> sd;
            }
            if (strcmp(textin -> operation, "pop") == 0){
                stack_a[i++] = 2;
                k = pop(stack);
            }
            if (strcmp(textin -> operation, "add") == 0){
                stack_a[i++] = 3;
                add(stack);
            }
            if (strcmp(textin -> operation, "sub") == 0){
                stack_a[i++] = 4;
                sub(stack);
            }
            if (strcmp(textin -> operation, "mul") == 0){
                stack_a[i++] = 5;
                mul(stack);
            }
            if (strcmp(textin -> operation, "divi") == 0){
                stack_a[i++] = 6;
                divi(stack);
            }
	}
}
void disassembler(FILE *disa, int *stack_a){
    int i = 0, chek = 1;
    while ((stack_a[i-1] !=0) && (stack_a[i] != 0)) {
        if (chek == 1){
            if (stack_a[i] == 1){
                fprintf(disa, "push ");
                chek = 0;
            }
            if (stack_a[i] == 2){
                fprintf(disa, "pop  \n");
            }
            if (stack_a[i] == 3){
                fprintf(disa, "add  \n");
            }
             if (stack_a[i] == 4){
                fprintf(disa, "sub  \n");
            }
             if (stack_a[i] == 5){
                fprintf(disa, "mul  \n");
            }
             if (stack_a[i] == 6){
                fprintf(disa, "divi \n");
            }
        } else{
            fprintf(disa, "%d\n", stack_a[i]);
            chek = 1;
        }
        i++;
    }
}
int main(){
    stack_t stack;
    struct inf textin;//аша считываемая информация
    int stack_a[maxsize];
    int i, k;
    FILE *mf, *getin, *disa;
    stack.size = 0;
    for (i = 0; i < maxsize; i++)
        stack_a[i] = 0;
    i = 0;
    mf = File1_ctor(mf);
    getin = File2_ctor(getin);
    disa = File3_ctor(disa);
    assembler(getin,stack_a, &stack,&textin);
    disassembler(disa, stack_a);
    while ((stack_a[i-1] !=0) && (stack_a[i] != 0)){
        printf("%d ", stack_a[i]);
        i++;
    }
    dump(&stack, mf);
    File_dtor(disa);
    File_dtor(getin);
    File_dtor(mf);
    return 0;
}

