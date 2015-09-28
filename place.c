#include <stdio.h>

int findelstr( char *str1, char a,int place ){  
	while (str1[place]!= a) //chek if element of our str1 = a
	{
		place++;	//move to the next str1 element
	}
	return place;//return the place where our element is
}

int main(){
	int i,place;//make counter
	char a;//make the simbol wee need to found
	
	scanf( "%c", &a );//read element we need to found
	scanf( "%d", &place );//read place where we start
	char str1[5];//make str1
	for (i = 0; i < 5; i++)  //read str1
		scanf("%c", &str1[i]);

	printf("%d", findelstr(str1,a,place));//printf the place
	return 0;
}
