#include <iostream>
#include <string>
#define r 2000
#define t 2000
using namespace std;


int table[r+1][t+1];

int lcs_length(string s,string p,int n,int m)
{
    if(n==0||m==0)
        return 0;
    if(table[n][m]==0)
    {
        if(s[n-1]==p[m-1])
        {
            table[n][m]=lcs_length(s,p,n-1,m-1)+1;
        }
        else
        {
            table[n][m]=max(lcs_length(s,p,n-1,m),lcs_length(s,p,n,m-1));
        }
    }
    return table[n][m];
}



string lcs(string s,string p,int n,int m)
{
    if(n==0||m==0)
        return string("");
    if(s[n-1]==p[m-1])
        return lcs(s,p,n-1,m-1)+s[n-1];

    else if(table[n-1][m]>table[n][m-1])
    {
       return lcs(s,p,n-1,m);
    }
    else
       return lcs(s,p,n,m-1);

}


int main()
{
   string s;
   string p;
   getline(cin,s);
   getline(cin,p);
  int z=lcs_length(s,p,s.size(),p.size());
  cout<< "the size of the subsequence is: "<<z<<endl;
  cout<<lcs(s,p,s.size(),p.size());

       return 0;
}
