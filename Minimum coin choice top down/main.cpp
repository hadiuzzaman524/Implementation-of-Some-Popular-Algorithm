#include <iostream>
#define inf 99999
using namespace std;
int minc(int target[] ,int coin[],int sum,int n)
{

    if(sum<1)
        return 0;
    if(target[sum] !=inf)
        return target[sum];
    for(int i=0;i<n;i++)
    {
        if(sum>=coin[i])
        {
            int temp=minc(target,coin,sum-coin[i],n);
            if(temp+1<target[sum])
                target[sum]=temp+1;
        }

    }
    return target[sum];
}
int main()
{
    int n;
    cout<< "how many coin? ";
    cin>>n;
    int coin[n];
    cout<< "enter the coin: ";
    for(int i=0; i<n; i++)
    {
        cin>>coin[i];
    }
    int sum;
    cout<< "Enter your target : ";
    cin>>sum;
    int target[sum+1];
    for(int i=0;i<=sum; i++)
        target[i]=inf;

    int z=minc(target,coin,sum,n);
    cout<< "the minimum coin is: "<<z<<endl;
    return 0;
}
