
#include"assembler.h"
void assembler(FILE *getin, struct inf *textin, int *stack_a)
{
	int i = 0;
	#define DEF_CMD(name, num) if(strcmp(textin -> operation, name) == 0)\
	{\
		stack_a[i] = num ;\
		i++;\
		if (num == push_num)\
		{\
			stack_a[i] = textin -> sd;\
			i++;\
		}\
	}
	while(fscanf (getin, "%s%d", textin -> operation, &(textin -> sd)) != EOF){
        #include "ASA.h"
      //  printf("");
        }
	#undef DEF_CMD
}
