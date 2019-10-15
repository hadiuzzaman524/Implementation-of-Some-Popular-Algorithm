#include <iostream>

using namespace std;
void msis(int ar[],int n)
{
    int sum[n]={0};
    sum[0]=ar[0];

    for(int i=1;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(ar[i]>ar[j]&&sum[j]>sum[i])
            {
                sum[i]=sum[j];
            }
        }
        sum[i]+=ar[i];
    }
    int m=0;
    for(int x:sum)
    {
        m=max(m,x);
    }
    cout<<m;
}

int main()
{
   int ar[]={8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11};
   int n=sizeof(ar)/sizeof(int);

   msis(ar,n);
    return 0;
}
