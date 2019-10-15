#include <iostream>
#include <map>
using namespace std;
//npr n!/c1!*c2!*......

int fact(int n)
{
    if(n<2)
        return 1;
    else
        return n*fact(n-1);
}


int main()
{
    string s;
    cin>>s;


    map<char,int>mp;
    map<char,int> ::iterator it;


    for(int i=0; s[i] !='\0'; i++)
    {
        mp[s[i]]++;
    }

    int len=s.size();
    int sum=fact(len);
    int all=1;
    for(it=mp.begin(); it !=mp.end(); it++)
    {
        all*=fact(it->second);
    }
    cout<<sum/all<<endl;


    return 0;
}
