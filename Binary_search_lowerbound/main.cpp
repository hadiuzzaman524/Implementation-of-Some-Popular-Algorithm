#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary(vector<int>ar,int low,int high,int key)
{

    int index;
    while(low<=high)
    {
        int mid=(low+high)/2;

        if(key==ar[mid])
        {
            index=mid;
            low=mid+1; //for upper bound.....
            //high=mid-1; //for lower bound........
           // break;
        }

        else if(key>ar[mid])
        {
            low=mid+1;
        }

        else if(key<ar[mid])
            high=mid-1;
    }
    return index;


}

int main()
{

    vector<int> ar{2,10,20,50,100,100,100,150,200,500,1000};


    int n=ar.size();
    cout<<n<<endl;

    int bin=binary(ar,0,n-1,100);
    //print lower index............
    cout<<bin<<endl;
    ar[bin]=400;
    sort(ar.begin(),ar.end());
    for(int i=0;i<ar.size();i++)
        cout<<ar[i]<<" ";
    cout<<endl;

    return 0;


}
