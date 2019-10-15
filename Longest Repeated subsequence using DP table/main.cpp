#include <iostream>
#include <string.h>
using namespace std;
int lrs(string s,int n)
{
    int table[n+1][n+1];
    memset(table,0,sizeof(table));

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s[j-1]&&i!=j)
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else

            table[i][j]=max(table[i-1][j],table[i][j-1]);
        }
    }
    return table[n][n];
}
int main()
{
   string s="ATACTCGGA";
    int n=s.length();
    cout<< "the length of longest repeated subsequence is: "<<lrs(s,n);

    return 0;
}
