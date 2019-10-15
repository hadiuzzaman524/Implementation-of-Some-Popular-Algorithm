#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int max(int a,int b)
{
    return a>b?a:b;
}

void lcs(char *x,char *y)
{
    int l1=strlen(x);
    int l2=strlen(y);

    int table[l1+1][l2+1];
    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            if(i==0||j==0)
                table[i][j]=0;

            else if(x[i-1]==y[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }

    for(int i=0;i<=l1;i++)
    {
        for(int j=0;j<=l2;j++)
        {
            printf("%d ",table[i][j]);
        }
        printf("\n");
    }

    int i=l1,j=l2;
    int index=table[i][j];
    string s;

    while(i>0&&j>0)
    {
        if(x[i-1]==y[j-1])
        {
          s+=x[i-1];
          i--;
          j--;
        }
        else if(table[i-1][j]>table[i][j-1])
        {
            i--;
        }
        else
            j--;

    }
cout<<s;

}
int main()
{
    char x[]="acbdab";
    char y[]="abcadac";
    lcs(x,y);

    return 0;
}
