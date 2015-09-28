#include <stdio.h>
int lenghtstr( char *str1 ){  
int i;
for(i=0;*str1!='\0';i++){//chek for the element is last
    str1++	//move our pointer;
   }
return i;	//return lenght str
}
void comparestr( char *str1,char *str2 ){  
		int i=0;//make counter
		while((str1[i]==str2[i])&&(str1[i]!='\0'))//compare our string

		{i++;//increase counter
		}
	if (i == lenghtstr(str1)){printf("YES");}//chek if our conter = lenght of string
	else{printf("NO");
}
}
int main(){
	char str1[5];//make str1
	char str2[5];//make str2 
	scanf("%s", str1);//read str1
	scanf("%s", str2);//read str2
	comparestr(str1,str2);
return 0;
}
