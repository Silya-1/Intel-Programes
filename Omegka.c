#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
void sor( int n,int **point)
{char *symb1, *symb2;
int j=0,i;
char *ret;
for(i = 0; i < n; i++) {
    for(j = 0; j < n  ; j++) {
        symb1 = point[j];
        symb2 = point[j+1];
        if (strcmp (symb1, symb2) > 0){
              int tmp;
              tmp = point[j];
              point[j] = point[j+1];
              point[j+1] = tmp;
              }
        }
}
}
int main()
{setlocale(LC_ALL, "rus");
FILE *mf;
char* str;
int i = 0,k = 0;
int *point;
char sym;
int t = 0;
char *ret;
mf=fopen ("C:/проги/Onegin/Onegin.txt","r");
while (1)
   {
    sym = fgetc (mf);
    t++;
     if (sym == '\n')
     k++;
     if (sym == '0')
      {
      fclose(mf);
      break;
      }
   }
t--;
str = (char*) malloc(t*sizeof(char));
mf=fopen ("C:/проги/Onegin/Onegin.txt","r");
while (1)
   {
    sym = fgetc(mf);
    str[i]=sym;
    i++;
     if (sym == '0')
        {
        fclose(mf);
        break;
        }
    }
for (i=0;i<t;i++) printf("%c",str[i]);
printf ("%d\n", k);
point = (int*)malloc(k*sizeof(int));
k=1;
point[0] = & str[0];
for (i=0;i<t;i++){
    if (str[i] == '\n'){
        point[k++] = &(str[i+1]);
        }

    }
k = k - 2;
sor(k, point);
for (i = 0; i <= k;i++){
    ret = point[i];
    printf("%c", *ret);
    }
free(str);
return 0;
}
