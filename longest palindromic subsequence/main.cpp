#include <iostream>
#include <string>
using namespace std;


int lps(string x,int i,int j)
{
    if(i>j)
        return 0;
    if(i==j)
        return 1;

    if(x[i]==x[j])
        return lps(x,i+1,j-1)+2;


    return max(lps(x,i+1,j),lps(x,i,j-1));
}
int main()
{
    string s="AGBDBA";
    int n=s.length();
    cout<<"the length is: "<<lps(s,0,n-1)<<endl;

    return 0;
}
