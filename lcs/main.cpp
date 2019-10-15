#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int max(int m, int n)
{
    int max;
    if (m>n)
        max=m;
    else
        max=n;
    return max;
}
void lcs(char x[],char y[])
{
    int i,j;
    int m=strlen(x);
    int n=strlen(y);
    char c[m+1][n+1];



    for(i=0; i<=m; i++)
    {
        for (j=0; j<=n; j++)
        {
            if(i==0||j==0)
                c[i][j]=0;


            else if(x[i-1]==y[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=max(c[i][j-1],c[i-1][j]);
        }
    }


    for(i=0; i<=m; i++)
    {
        for(j=0; j<=n; j++)
            printf("%d ",c[i][j]);
        printf("\n");
    }
}


int main()
{
    char x[]="acbdab";
    char y[]="abcadac";
    puts(x);
    puts(y);
    lcs(x,y);

    return 0;
}
