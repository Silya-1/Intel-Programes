#include <stdio.h>
int lenghtstr( char *str ){  
int i;//make counter
for(i=0;*str!='\0';i++){//chek for the element is last
   	    str++;//move pointer
       	}
	return i;	//return lenght str
}
int main(){
	int i;
	char str[5];//make str
	for( i = 0 ; i < 5 ; i++){  //read str
 		scanf("%c",&str[i]);
	}
printf( "%d",lenghtstr(str));//printf lenght our string
return 0;
}
