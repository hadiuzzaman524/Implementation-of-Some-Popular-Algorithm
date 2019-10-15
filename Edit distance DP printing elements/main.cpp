#include <iostream>
using namespace std;
int table[20][20];


int edit(string s,string p,int m,int n)
{
    table[m+1][n+1];

    for(int i=0; i<=m; i++)
        table[i][0]=i;

    for(int i=0; i<=n; i++)
        table[0][i]=i;

    int cost;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(s[i-1]==p[j-1])
            {
                cost=0;
            }
            else
            {
                cost=1;
            }

            table[i][j]=min(min(table[i][j-1]+1,table[i-1][j]+1),table[i-1][j-1]+cost);
        }
    }
    return table[m][n];
}


void print(string s,string p,int m,int n)
{
    int i=m;
    int j=n;
    while(i||j)
    {
        if(s[i-1]==p[j-1])
        {
            i--;
            j--;
            continue;
        }
        if(j>0&&table[i][j]==table[i][j-1]+1)
        {
            cout<< "I "<<p[j-1]<<j<<endl;
            s.insert(i,1,p[j-1]);
            j--;

        }
        else if(i>0&&j>0&&table[i][j]==table[i-1][j-1]+1)
        {
            cout<< "C "<<p[j-1]<<j<<endl;
            s[i-1]=p[j-1];
            i--;
            j--;
        }
        if(i>0&&table[i][j]==table[i-1][j]+1)
        {
            cout<< "D "<<s[i-1]<<i<<endl;

            s.erase(i-1,1);
            i--;
        }
    }
    cout<<s<<endl;

}

int main()
{
    string x="aaa";
    string y="aabaaaa";
    int m=x.size();
    int n=y.size();
    int z=edit(x,y,m,n);
    cout<<z<<endl;



    cout<<endl<<endl;
    print(x,y,m,n);

    return 0;
}
