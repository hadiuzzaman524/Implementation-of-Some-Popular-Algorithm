#include <iostream>
#include <string>
using namespace std;
//this program taken O(2^n+m) time.................

int lcs(string s,string p,int n,int m)
{
  if(n==0||m==0)
    return 0;
  else if(s[n-1]==s[m-1])
  {
      return lcs(s,p,n-1,m-1)+1;
  }
  else
  {
      return max(lcs(s,p,n-1,m),lcs(s,p,n,m-1));
  }
}

int main()
{
  string s="ABCABDE";
  string p="ABCDE";

  int z=lcs(s,p,s.size(),p.size());
  cout<< "the length of the subsequence is: "<<z<<endl;


 return 0;
}
