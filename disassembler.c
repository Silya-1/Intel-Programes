#include"assembler.h"
void disassembler(FILE *disa, int *stack_a)
{
	int i = 0;
	#define DEF_CMD(name, num) if(stack_a[i] == num)\
	{\
		fprintf(disa, name );\
		i++;\
		if (num == push_num)\
		{\
			 fprintf(disa, " %d", stack_a[i]);\
			i++;\
		}\
        fprintf(disa, "\n" );\
	}
	while((stack_a[i-1] !=0) && (stack_a[i] != 0)){
        #include "ASA.h"
      //  printf("");
        }
	#undef DEF_CMD
}

