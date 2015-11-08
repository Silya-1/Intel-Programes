#include"stack.h"
void push(stack_t *stack, int element);
int pop(stack_t *stack);
void add(stack_t *stack);
void sub(stack_t *stack);
void mul(stack_t *stack);
void divi(stack_t *stack);
void preprosessor(int *stack_a, stack_t *stack)
{
    int t,i = 0;
    //int t = 1;
    for (i = 0; i < maxsize; i++){
        if (stack_a[i] == push_num){
            i++;
            t = stack_a[i];
            push(stack, t);
           // printf("%d", stack_a[i]);
          //  printf("%d", stack -> mas[0]);
            }
        else {
        if (stack_a[i] == pop_num)
            pop(stack);
         if (stack_a[i] == add_num)
            add(stack);
         if (stack_a[i] == sub_num)
            sub(stack);
         if (stack_a[i] == mul_num)
            mul(stack);
         if (stack_a[i] == divi_num)
            divi(stack);

    }
    }

}
