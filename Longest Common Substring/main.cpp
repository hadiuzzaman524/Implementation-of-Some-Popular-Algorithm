#include <iostream>
#include <string>
#include <string.h>
using namespace std;


string lcs(string s,string p)
{
    int n=s.size();
    int m=p.size();
    int table[n+1][m+1];
    memset(table,0,sizeof(table));
    int big=0;
    int index;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(s[i-1]==p[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
                if(big<table[i][j])
                {
                    big=table[i][j];
                    index=i;
                }
            }
        }
    }

    return s.substr(index-big,big);
}



int main()
{
    string s="ABCDE";
    string p="ACDE";
    cout<<lcs(s,p);
    return 0;
}
