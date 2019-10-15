#include <iostream>

using namespace std;
int distance_(string x,string y,int m,int n)
{
    if(m==0)
        return n;
    if(n==0)
        return m;

    int cost;
    if(x[m-1]==y[n-1])
    {
        cost=0;
    }
    else
    {
        cost=1;
    }

    return min(min(distance_(x,y,m-1,n)+1,distance_(x,y,m,n-1)+1),distance_(x,y,m-1,n-1)+cost);



}
int main()
{
    string x="kitten";
    string y="sitting";
    int m=x.length();
    int n=y.length();

    int z=distance_(x,y,m,n);
    cout<< "total number of operation is: "<<z<<endl;
    return 0;
}
