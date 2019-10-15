#include <iostream>
#include <string>
using namespace std;
int table[20][20];
int lrs(string s,int n)
{
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(s[i-1]==s[j-1] &&i !=j)
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=max(table[i-1][j],table[i][j-1]);
            }
        }
    }
    return table[n][n];
}
string lrs(string s,string p,int i,int j)
{
    if(i==0||j==0)
        return string("");
    if(s[i-1]==s[j-1]&&i !=j)
    {
        return lrs(s,p,i-1,j-1)+s[i-1];
    }
    else if(table[i-1][j]>table[i][j-1])
    {
        return lrs(s,p,i-1,j);
    }
    else
        return lrs(s,p,i,j-1);
}
int main()
{

    string s="ATACTCGGA";
    string p=s;
    int n=s.length();
    cout<< "the length of longest repeated subsequence is: "<<lrs(s,n)<<endl;
    cout<<"the repeated subsequence is: "<<lrs(s,p,n,n);

    return 0;
}
