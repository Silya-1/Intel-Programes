#include<stdio.h>
#include <assert.h>
int lengthstr( char *str1 )
{
    int i;
     assert(str1!=NULL);
    for(i = 0; str1[i] != '\0'; i++){}//chek for the element is last
    return i;	//return lenght str
}

void copystr(char *str1, char *str2 ){
     assert(str1!=NULL);
    while((*str2++ = *str1++) != '\0'){}//make copy
}

int findelstr( char *str1, char a ){
	int i ;
	assert(str1!=NULL);
	assert(a);
	for (i=1;i<=lengthstr(str1);i++){
    if (*str1 == a){return i;}
    str1++;
	}
	return -1;//return counter which shows the place
}

void comparestr(char *str1, char *str2)
{
    int i = 0;//make counter
    assert(str1!=NULL);
    while ((str1[i] == str2[i]) && (str1[i] != '\0'))//compare our string
        i++; //increase counter
	if (i == lengthstr(str1))
        printf("YES");//chek if our conter = lenght of string
	else
        printf("NO");
}

int findelstrfrom(char *str1, char a, int place){

    int i;
    assert(str1!=NULL);
    assert(a);
    assert(place);
	for (i = (place-1);i<=lengthstr(str1);i++){
    if (str1[i] == a){return i+1;}
	}
	return -1;//return the place where our element is
}
