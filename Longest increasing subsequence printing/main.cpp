#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int lis(int ar[],int n)
{
    vector<int>la[n];
    la[0].push_back(ar[0]);

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(ar[j]<ar[i]&&la[i].size()<la[j].size())
            {
                la[i]=la[j];
            }
        }
        la[i].push_back(ar[i]);
    }


    /* for(int i=0;i<n;i++)
     {
         for(int j=0;j<la[i].size();j++)
         {
             cout<<la[i][j]<< " ";
         }
         cout<<endl;
     }*/
    int j=0,k=0;
    for(int i=1; i<n; i++)
    {
        if(la[j].size()<la[i].size())
            j=i;
    }
    for(int i=0; i<la[j].size(); i++)
    {
        cout<<la[j][i]<< " ";
        k++;
    }
return k;
}

int main()
{
    int ar[]= { 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
    int n=sizeof(ar)/sizeof(int);
    int z=lis(ar,n);
    cout<<endl;
    cout<< "the length of the longest increasing subsequence is: "<<z<<endl;
    return 0;
}
