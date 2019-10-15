#include <iostream>

using namespace std;
int table[20][20];

//int table[j+1][k+1];

int lcs(string s,string p,int n,int m)
{
    if(n==0||m==0)
        return 0;
    if(table[m][n]==0)
    {
        if(s[n-1]==p[m-1])
            table[m][n]=lcs(s,p,n-1,m-1)+1;
        else
            table[m][n]=max(lcs(s,p,n-1,m),lcs(s,p,n,m-1));
    }
   return table[m][n];



}
int main()
{
        string s="ABCABDE";
    string p="ABCDE";

    int m=s.size();
    int n=p.size();


    cout<< "the shortest common super sequence length is: "<<lcs(s,p,m,n)<<endl;

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }
    //cout<<endl<<"the shortest common sequence is: "<<scsp(s,p,m,n)<<endl;


    return 0;
}
