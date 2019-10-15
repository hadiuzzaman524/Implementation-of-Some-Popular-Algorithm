#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int minsum(int s[],int n,int s1,int s2)
{
    if(n<0)
    {
        return abs(s1-s2);
    }
    unordered_map <string,int>lookup;
    string key=to_string(n)+"|"+to_string(s1);

    if(lookup.find(key)==lookup.end())
    {
        int inc=minsum(s,n-1,s1+s[n],s2);
        int exc=minsum(s,n-1,s1,s2+s[n]);

        lookup[key]=min(inc,exc);
    }



    return lookup[key];
}

int main()
{

    int S[] = { 10, 20, 15, 5, 25};
    int n=sizeof(S)/sizeof(int);
    int sum=minsum(S,n-1,0,0);
    cout<< "minimum sum is: "<<sum<<endl;


    return 0;
}
