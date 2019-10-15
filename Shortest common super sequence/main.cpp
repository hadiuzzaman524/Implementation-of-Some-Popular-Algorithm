#include <iostream>
#include <string>
#include <string.h>
using namespace std;
int scs(string x,string y,int m,int n);
string scs_print(string x,string y,int m,int n);
int table[20][20];

int main()
{
    string s="abcbdab";
    string p="bdcaba";
    int m=s.length();
    int n=p.length();
    int len=scs(s,p,m,n);
    cout<< "the length of shortest common supersequence is: "<<len<<endl;
    cout<<"the common super_sequence is: "<<scs_print(s,p,m,n)<<endl<<endl;
    return 0;
}


int scs(string x,string y,int m,int n)
{
  //  int table[m+1][n+1];


    for(int i=0;i<=m;i++)
    {
        table[i][0]=i;
    }
    for(int j=0;j<=n;j++)
    {
     table[0][j]=j;
    }

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i-1]==y[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=min(table[i-1][j]+1,table[i][j-1]+1);
            }
        }
    }
    return table[m][n];
}


string scs_print(string x,string y,int m,int n)
{
    if(m==0)
    {
        return y.substr(0,n);
    }

    else if(n==0)
    {
      return x.substr(0,m);
    }

    if(x[m-1]==y[n-1])
    {
        return scs_print(x,y,m-1,n-1)+x[m-1];
    }
    else
    {
        if(table[m-1][n]<table[m][n-1])
        {
            return scs_print(x,y,m-1,n)+x[m-1];
        }
        else
        {
            return scs_print(x,y,m,n-1)+y[n-1];
        }
    }

}
