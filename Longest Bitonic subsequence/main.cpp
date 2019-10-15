#include <iostream>
using namespace std;

int lbs(int ar[],int n);

int main()
{
   int ar[]={4,2,5,9,7,6,10,3,1};
   int n=sizeof(ar)/sizeof(int);

   int z=lbs(ar,n);
   cout<<endl;
   cout<< "the length of the longest bitonic subsequence is: "<< z<<endl;
    return 0;
}
int lbs(int ar[],int n)
{
    int d1[n]={0};
    int d2[n]={0};

    d1[0]=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(ar[j]<ar[i]&&d1[j]>d1[i])
            {
                d1[i]=d1[j];
            }
        }
        d1[i]++;
    }

     d2[n-1]=1;
    for(int i=n-2;i>=0;i--)
    {
        for(int j=n-1;j>i;j--)
        {
            if(ar[j]<ar[i]&&d2[j]>d2[i])
            {
                d2[i]=d2[j];
            }
        }
        d2[i]++;
    }

  int m=0;
  for(int i=0;i<n;i++)
  {
      m=max(d1[i]+d2[i]-1,m);
  }
  return m;


}
