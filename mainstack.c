#include"stack.h"
int main(){
    stack_t stack;
    struct inf textin;
    int i;
    int stack_a[maxsize];
    FILE *mf, *getin, *disa;
    inf_ctor(&textin);
    stack_ctor(&stack);
    zermas(stack_a);
    mf = File1_ctor(mf);
    getin = File2_ctor(getin);
    disa = File3_ctor(disa);
    assembler(getin, &textin, stack_a);
    preprosessor(stack_a,&stack);
    disassembler(disa, stack_a);
    dump(&stack, mf);
    File_dtor(disa);
    File_dtor(getin);
    File_dtor(mf);
    return 0;
}
