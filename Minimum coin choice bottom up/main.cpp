#include <iostream>

using namespace std;
int minc(int coin[],int sum,int n)
{

 int target[sum+1];
 for(int i=0; i<=sum; i++)
 {
     target[i]=9999;
 }
 target[0]=0;

 for(int i=1; i<=sum; i++)
 {
     for(int j=0; j<n; j++)
     {
         if(coin[j]<=i)
         {
             int temp=target[i-coin[j]] +1 ;
             if(temp< target[i])
             {
                 target[i]=temp;
             }
         }
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
 int z=minc(coin,sum,n);
 cout<< "the minimum coin is: "<<z<<endl;

    return 0;
}
