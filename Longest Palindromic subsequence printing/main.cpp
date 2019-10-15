#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;


int table[20][20];
string lcs(string s,string p,int i,int j)
{
    if(i==0||j==0)
        return string("");
    if(s[i-1]==p[j-1])
    {
        return lcs(s,p,i-1,j-1)+s[i-1];
    }
    else if(table[i-1][j]>table[i][j-1])
    {
        return lcs(s,p,i-1,j);
    }
    else
        return lcs(s,p,i,j-1);

}

int lcs(string s,string p,int n)
{
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(s[i-1]==p[j-1])
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


int main()
{
   string s="AGBDBA";
   string p=s;
   reverse(p.begin(),p.end());
   int m=s.length();
   cout<<"the length of the palindromic subsequence is: "<<lcs(s,p,m)<<endl;
   cout<< "the palindromic subsequence is: "<<lcs(s,p,m,m);

    return 0;
}
