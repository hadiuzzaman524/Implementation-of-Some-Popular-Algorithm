#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int scs(string s,string p)
{
    int m=s.length();
    int n=p.length();



    int table[m+1][n+1];
    for(int i=0; i<=m; i++)
    {
        table[i][0]=i;
    }


    for(int i=0; i<=n; i++)
    {
        table[0][i]=i;
    }


    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1]==p[j-1])
            {
                table[i][j]=table[i-1][j-1]+1;
            }
            else
            {
                table[i][j]=min(table[i][j-1]+1,table[i-1][j]+1);
            }

        }
    }

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }


    return table[m][n];
}

int main()
{
    string s="XMJYAUZ";
    string p="XMJAATZ";

    int m=s.length();
    int n=p.length();

    cout<< "the shortest common super sequence length is: "<<scs(s,p)<<endl;
  //  cout<< print(s,p,m,n,table)<<endl;




    return 0;
}
