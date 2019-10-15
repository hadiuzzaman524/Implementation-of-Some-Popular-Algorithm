#include <iostream>

using namespace std;
bool subsetsum(int ar[],int n,int sum)
{

    bool table[n+1][sum+1];

    for(int i=1;i<=sum;i++)
        table[0][i]=false;

    for(int i=0;i<=n;i++)
        table[i][0]=true;

    for(int i=1; i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(ar[i-1]>j)
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                table[i][j]=table[i-1][j]||table[i-1][j-ar[i-1]];
            }
        }
    }
    return table[n][sum];
}

bool partition(int ar[],int n)
{

    int sum=0;
    for(int i=0;i<n; i++)
        sum+=ar[i];

    if(sum%2==0)
    {
        return subsetsum(ar,n,sum/2);
    }
    else
    {
        return false;
    }
}

int main()
{
    int ar[]={7,3,1,5,4,8};
    int n=sizeof(ar)/sizeof(int);

    if(partition(ar,n))
        cout<< "yes"<<endl;
    else
        cout<< "No"<<endl;

    return 0;
}
