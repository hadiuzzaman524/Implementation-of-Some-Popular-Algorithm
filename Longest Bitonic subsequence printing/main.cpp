#include <iostream>
#include <list>
using namespace std;

void lbs(int ar[],int n)
{
    list<int>list1[n];
    list<int>list2[n];

    list1[0].push_back(ar[0]);
    //longest increasing subsequence
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if(ar[j]<ar[i]&&list1[i].size()<list1[j].size())
            {
                list1[i]=list1[j];
            }

        }
        list1[i].push_back(ar[i]);
    }
    //longest decreasing subsequence

    list2[n-1].push_front(ar[n-1]);

    for(int i=n-2; i>=0; i--)
    {
        for(int j=n-1; j>i; j--)
        {
            if(ar[i]>ar[j]&&list2[i].size()<list2[j].size())
            {
                list2[i]=list2[j];
            }
        }
        list2[i].push_front(ar[i]);
    }
  //printing the element
    /*  for(int i=0; i<n; i++)
      {
          for(int j:list1[i])
              cout<< j<< " ";
          cout<<endl;
      }
      cout<<endl;

      for(int i=0; i<n; i++)
      {
          for(int j:list2[i])
              cout<< j<< " ";
          cout<<endl;
      }
    cout<<endl<<endl;
    */

    int pik=0;

    for(int i=1; i<n; i++)
    {
        int m=list1[i].size()+list2[i].size();
        int k=list1[pik].size()+list2[pik].size();
        if(m>k)
            pik=i;
    }
    cout<<pik<<endl;
    for(int i:list1[pik])
        cout<<i<< " ";

    list2[pik].pop_front();

    for(int j:list2[pik])
        cout<< j<< " ";
    cout<<endl;

}

int main()
{
    int ar[]= {4,2,5,9,7,6,10,3,1};
    int n=sizeof(ar)/sizeof(int);

    lbs(ar,n);
    cout<<endl;
    return 0;

}
