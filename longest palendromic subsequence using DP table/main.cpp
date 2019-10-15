#include <iostream>
#include <string.h>
using namespace std;
int lps(string s,int n)
{
    int table[n][n];
    memset(table,0,sizeof(table));
    for(int i=0;i<=n;i++)
    {
        table[i][i]=1;
    }
    for(int m=1;m<n;m++)
    {
        for(int i=0;i<n-m;i++)
        {
            int j=m+i;
            if(s[i]==s[j])
            {
                table[i][j]=table[i+1][j-1]+2;
            }
            else
            {
                table[i][j]=max(table[i+1][j],table[i][j-1]);
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }

    return table[0][n-1];
}
int main()
{
    string s="AGBDBA";
    int n=s.length();
    cout<<"the length is: "<<lps(s,n)<<endl;

    return 0;
}
