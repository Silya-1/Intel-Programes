#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct tree {
  char qestion[100];
  struct tree *yes;
  struct tree *no;
};
 void dtree(struct tree *man)
{
    if (man == NULL)
        return;
    dtree(man -> yes);
    dtree(man -> no);
    free(man -> no);
    free(man -> yes);
    man -> no = NULL;
    man -> yes = NULL;
    return;

}
FILE* File1_ctor(FILE *mf){
    mf =  fopen("MAINQESTIONS.txt", "w");
    return mf;
}
FILE* File2_ctor(FILE *mf){
    int p = 0;
    mf =  fopen("MAINQESTIONS.txt", "r");
    p = fgetc(mf);
   // printf("%c",p);
    return mf;
}
struct tree* addqestion(struct tree *man)
{
    if (man == NULL)
    {   int c, p = 0;
        man = malloc(sizeof(struct tree));
        while((c = getchar())!= '\n')
            man ->qestion[p++] = c;
        man ->qestion[p] = '\0';
        //scanf("%s",man->qestion);
        man -> yes = NULL;
        man -> no = NULL;
    }
    return man;
}
struct tree* addanswer(struct tree *man)
{
    if (man == NULL)
    {
       int c, p = 0;
        man = malloc(sizeof(struct tree));
        while((c = getchar())!= '\n')
            man ->qestion[p++] = c;
        man ->qestion[p] = '\0';
        //scanf("%s",man->qestion);
        man -> yes = NULL;
        man -> no = NULL;
    }
    return man;
}
void tprint(struct tree *man)
{
    if (man == NULL)
        return;
        tprint(man -> yes);
        printf(" %s ", man -> qestion);
        tprint(man -> no);
       return;
}
void fileprint(struct tree *man, FILE *mf)
{
    if (man == NULL)
        return;
    fprintf(mf,"(%s", man -> qestion);
    fileprint(man -> yes, mf);
    fileprint(man -> no, mf);
    fprintf(mf,")");
    return;
}
struct tree * treemake(struct tree *man, FILE *mf, int k,int w)
{
   int c, p = 0;
   man = calloc(1,sizeof(struct tree));
    c = fgetc(mf);
       while (c != EOF)
       {
        if ((c != ')')&&(c != '('))
        {
            man -> qestion[p++]= c;
            //printf("%c", man -> qestion[p -1]);
        }

        if ((c == '(')&&(k == 0))
        {
            man->yes = treemake(man -> yes,mf,0,0);
            k = 1;
            w = 1;
            c = fgetc(mf);
        }
        if ((c == '(')&&(k == 1))
        {
            man->no = treemake(man -> yes,mf,0,0);
            c = fgetc(mf);
        }
         if (c == ')')
         {    if(w == 0)
             {
          //  printf("%s", man -> qestion);
              man -> yes = NULL;
              man -> no = NULL;
             }

             return man;
         }
         c = fgetc(mf);

      }
      return man;



}
void File_dtor(FILE *mf){
    fclose(mf);
}
void akinatorgo(struct tree *man)
{   char a[2];
    int c,k;
    int p = 0;
    char aro[30];
    for(;;)
     {

        printf("%s?(y/n)", man -> qestion);
        printf("\n");
        scanf("%s", a);
        if (a[0] == 'y')
        {
            if(man -> yes != NULL)
            {
                man = man ->yes;
            }
            else
            {
                 printf("I KNOW IT");
                 return;
            }
        }
        else
            if (a[0] == 'n')
        {
        if(man -> no != NULL)
        {
            man = man -> no;
        }

        else
            {    printf("Who is it\n");
                 man -> no = calloc(1,sizeof(struct tree));
                 man -> yes = calloc(1,sizeof(struct tree));
                 scanf("%s",man -> yes -> qestion);
                 memcpy(man ->no -> qestion,man->qestion,strlen(man -> qestion));
                 printf("what's different between %s and %s",man -> no -> qestion, man -> yes -> qestion);
                 printf("\n");
                 for(k = 0; k < 100; k++)
                 {
                      man -> qestion[k] = 0;
                      //printf("ggg");
                      //printf("%c",man -> qestion[k]);
                 }
                 scanf("\n");
                    do
                  {

                    scanf("%c",&aro[p++]);
                    //printf("%c", aro[p-1]);
                    man -> qestion[p-1]= aro[p-1];
                    //scanf("%d",&c);
                   // memcpy(&man -> qestion[strlen(man -> qestion)],aro, strlen(aro));
                  }
                 while (aro[p-1] != '\n');

                man ->qestion[p-1] = '\0';
                     //scanf("%s", man -> qestion);
                    //  man -> qestion[0] = 'p';
                   // man = addqestion(man);
                 man -> yes -> yes = NULL;
                 man -> yes -> no = NULL;
                 man -> no -> yes = NULL;
                 man -> no -> no = NULL;
                 return;
            }
        }
    }
}
int main()
{
    struct tree *man;
    man = NULL;
    FILE *mf;
    mf = File2_ctor(mf);
   // man = addqestion(man);
    //man -> yes = addanswer(man -> yes);
    //man -> no = addanswer(man -> no);
    printf("\n");
    man = treemake(man,mf,0,1);
    File_dtor(mf);
   // mf = File1_ctor(mf);
    akinatorgo(man);
   // printf(" %s", man -> yes->  qestion);
    //tprint(man);
    mf = File1_ctor(mf);
    fileprint(man, mf);
    return 0;

}
