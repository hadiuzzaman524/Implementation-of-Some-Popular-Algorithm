#include <iostream>
#include <vector>
using namespace std;
vector< vector<int> >v (100,vector<int>(100,-1));
int knapsack(int waight[],int prof[],int n,int i,int j)
{
    if(i==0||j==0)
        return 0;
    if(v[i][j] !=-1)
        return v[i][j];
    int take,lave;
    if(waight[i]>j)
    {
        v[i][j]=knapsack(waight,prof,n,i-1,j);
    }
    else
    {
        lave=knapsack(waight,prof,n,i-1,j);
        take=knapsack(waight,prof,n,i-1,j-waight[i])+prof[i];
        v[i][j]=max(take,lave);
    }

    return v[i][j];
}
int main()
{
    int n;
    cout<< "how many element: ";
    cin>>n;
    int waight[n+1],prof[n+1];
    waight[0]=0;
    prof[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>waight[i]>>prof[i];
    }
    int s;
    cout<< "enter the size of knapsack: ";
    cin>>s;

    int z=knapsack(waight,prof,n,n,s);
    cout<< "the max prof is: "<<z<<endl;
    int i=n,j=s;
    cout<< "selected item are: ";
    while(i>0&&j>0)
    {
        if(v[i][j] !=v[i-1][j])
        {
            cout<<i<< " ";
            j=j-waight[i];
            i--;

        }
        i--;
    }

    return 0;
}
