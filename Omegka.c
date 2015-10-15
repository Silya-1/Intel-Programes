#include <stdio.h>
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
void sor( int n,char *point){
int i, j;
char t;
    for(i=0;point[i]!='\0';i++)
        {
            for(j=i+1;point[j]!='\0';j++)
            {
                if (point[i]>point[j])
                {
                    t=point[i];
                    point[i]=point[j];
                    point[j]=t;
                }
            }
        }
    }

int main()
{setlocale(LC_ALL, "rus");//make russiun 
FILE *mf;//our file
char *str;//our text
int i = 0,k = 0;
char *point;//array pointers
char sym;
int t = 0;
char *ret;
str = (char*) calloc(i,sizeof(char));//make  zerro string
point = (char*)calloc(k,sizeof(char));//make zerro array
mf=fopen ("C:/проги/Onegin/Onegin.txt","r");//open our file
while (1)
   {

     sym = fgetc (mf);//sym is a simbol from file
     //printf("%c", sym);
     if (sym == '0')//chek if file is end
      {
      fclose(mf);
      break;
      }
    str[i] = sym;//add simbol to string
    if(i == 0)
    realloc(str,i);//increase our strinh
    i++;
    t++;
     if (sym == '\n')//chek if string is end

     k++;//increase number of elements in array
   }
t-=1;//minus 1 from t ?cause the last simbol is 0
i--;
realloc(str,i);//delet the last simbol in string
realloc(point,k);
for (i=0;i<t;i++) printf("%c",str[i]);
printf ("%\n");
printf ("%d\n", k);
k=1;
point[0] = str[0];//save point for first string
for (i=0;i<t;i++){
    if (str[i] == '\n'){
        point[k++] = (str[i+1]);//save points for str
        }

    }
k = k - 2;//count minus 2 cause 2 last \n we don't need
sor(k, point);//make sort
for (i = 0; i <= k;i++)
    printf("%c", *point++);
free(str);
free(point);
return 0;
}

