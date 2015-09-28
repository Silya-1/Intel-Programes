#include <stdio.h>
void copystr( char *str1,char *str2 ){  
while((*str2++=*str1++)!=0){}//make copy
}
int main(){
	int i;
	char str1[5];//make str1
	char str2[5]={};//make str2
	for( i = 0 ; i < 5 ; i++){  //read str1
		scanf("%c",&str1[i]);
	}
copystr( str1,str2 );
for( i = 0 ; i < 5 ; i++){  //printf copied string
		printf("%c",str2[i]);
}
return 0;
}
