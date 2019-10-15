#include <iostream>
#include <string>
using namespace std;



int lrs(string s,string p,int i,int j)
{
    if(i==0||j==0)
        return 0;
    if(s[i-1]==p[j-1]&&i !=j) //same index is not equal because same index means one word
    {
        return lrs(s,p,i-1,j-1)+1;
    }
    return max(lrs(s,p,i-1,j),lrs(s,p,i,j-1));
}



int main()
{
    string s="ATACTCGGA";
    string p=s;
    int n=s.length();
    cout<< "the length of longest repeated subsequence is: "<<lrs(s,p,n,n);
    return 0;
}
