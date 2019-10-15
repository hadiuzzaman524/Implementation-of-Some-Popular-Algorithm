#include <iostream>

using namespace std;

int main()
{
   int n;
   int target;
   cin>>n>>target;
   int ar[n];
   for(int i=0; i<n; i++)
    cin>>ar[i];
   int m=0;
   int rem;
   for(int a=0;a<n;a++)
   {
       int k=target%ar[a];
       if(k<=m)
       {
          m=k;
          rem=ar[a];
       }

   }
cout<<m<< " "<<rem;
    return 0;
}
