#include <stdio.h>

int findelstr( char *str1, char a ){  
	int i = 0;
	while (*str1!= a) //chek if element of our str1 = a
	{
		i++;//increase our counter
		str1++;//move our pointer
	}
	return i;//return counter which shows the place
}

int main(){
	int i;//make counter
	char a;//make the simbol wee need to found
	scanf( "%c", &a );//read element we need to found
	char str1[5];//make str1
	for (i = 0; i < 5; i++)  //read str1
		scanf("%c", &str1[i]);

	printf("%d", findelstr(str1, a));//print the place
	return 0;
}
