#include <iostream>

using namespace std;

int lis(int ar[],int n)
{

    int  la[n]={0};

    la[0]=1;

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ar[j]<ar[i]&&la[j]>la[i])
            {
                la[i]=la[j];
            }
        }
        la[i]++;
    }

    int r=0;
    for(int x:la)
        r=max(r,x);

    return r;
}


int main()
{
    int ar[]= {1,3,10,6,7,9,5,2,4};
    int n=sizeof(ar)/sizeof(int);
    int z=lis(ar,n);
    cout<<endl;
    cout<< "the length of the longest increasing subsequence is: "<<z<<endl;
    return 0;
}
