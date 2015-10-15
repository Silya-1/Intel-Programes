#include <stdio.h>
void makematrix(int n, int m,int *M[n][m] ){
    int i,j;
    for (i=0;i<n;i++){
        for(j=0;j<m;j++)
        scanf("%d",&M[i][j]);}
}

void sortmatrix(int n, int m,int *M[n][m] ){
    int i,j,f,r;
   // printf("you");
    do
        {
        f=0;//chek if matrix is sorted
        for (i=0; i<n; i++){
            for (j=0; j<n-1; j++)
            if (M[i][j]>M[i][j+1])
                {
                r=M[i][j];
                M[i][j]=M[i][j+1];
                M[i][j+1]=r;
                f=1;
                }
             if ((i>0)&&(M[i-1][j]>M[i][0])){
               r=M[i-1][j];
                M[i-1][j]=M[i][0];
                M[i][0]=r;
                f=1;
             }
        }
    }
        while (f!=0);
}

void printmatrix(int n, int m,int *M[n][m] ){
    int i,j;
    printf("\n");
    for (i=0;i<n;i++){
        for(j=0;j<m;j++)
        printf("%d ",M[i][j]);
        printf("\n");
        }
}

int main()
{   int m,n,i,j,f,r;
    scanf("%d %d",&n,&m);
    int M[n][m];
    makematrix(n,m,M);
    sortmatrix(n,m,M);
    printmatrix(n,m,M);;
return 0;
}
