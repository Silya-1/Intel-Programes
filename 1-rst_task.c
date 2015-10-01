#include <stdio.h>
#include <stdlib.h>

int main(){
	char *str1 = (char *)malloc(5 * sizeof(char*)); //make str1
	char *str2 = (char *)malloc(5 * sizeof(char*)); //make str2
	int length, place;
	char element;
	scanf("%c", &element);
	scanf("%d", &place);
	scanf("%s", str1);//read str1
	//length = lengthstr(str1); //find lenght of our string
	//printf("%d\n", length); //print the lenght of string
	//copystr(str1, str2 );
	//printf("%s\n", str2);
	//place = findelstr(str1, element);
	//scanf("%s", str2); //read str2
	//printf("%d", place);
	//printf("%d\n",findelstr(str1, element));
	//comparestr(str1, str2);
	printf("%d", findelstrfrom(str1, element, place));

    return 0;
}
