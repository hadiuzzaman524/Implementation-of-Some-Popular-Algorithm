#include <iostream>

using namespace std;
void marge(int ar[],int low,int mid,int high)
{
    int n1=mid-low+1;
    int n2=high-mid;
    int la[n1];
    int ra[n2];
    for(int i=0; i<n1; i++)
        la[i]=ar[low+i];
    for(int j=0; j<n2; j++)
        ra[j]=ar[mid+1+j];
    int i=0,j=0,k=low;
    while(i<n1&&j<n2)
    {
        if(la[i]<ra[j])
        {
            ar[k]=la[i];
            i++;
        }
        else
        {
            ar[k]=ra[j];
            j++;
        }
        k=k+1;
    }
    while(i<n1)
    {
        ar[k]=la[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        ar[k]=ra[j];
        j++;
        k++;
    }
}
int marge_sort(int ar[],int low,int high)
{
    if(low<high)
    {
        int mid=low+(high-low)/2;
        marge_sort(ar,low,mid);
        marge_sort(ar,mid+1,high);
        marge(ar,low,mid,high);
    }

}
int main()
{
    int ar[]= {4,3,2,55,33,21,45,36,84,44,99,1};
    int n=sizeof(ar)/sizeof(int);
    marge_sort(ar,0,n-1);
    cout<< "the marge sort result is: "<<endl;
    for(int a:ar)
        cout<<a<< " ";

    return 0;
}
