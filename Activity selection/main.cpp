#include <iostream>
#include <algorithm>
using namespace std;
class Activity
{
public:
    int activity_no,starting,ending;


    void set(int a,int b,int c)
    {
        activity_no=a;
        starting=b;
        ending=c;
    }


};


bool comp(Activity a,Activity b)
{
    if(a.ending!=b.ending)
        return a.ending<b.ending;
}


int main()
{

    int n;
    cout<< "how many activity? ";
    cin>>n;


    Activity obj[n];


    for(int i=0; i<n; i++)
    {
        cout<< "enter starting time and ending time of the activity "<<i+1<< " : ";
        int a,b;
        cin>>a>>b;
        obj[i].set(i+1,a,b);
    }


    sort(obj,obj+n,comp);
    /*  for(int i=0;i<n;i++)
      {
          cout<< obj[i].activity_no<< "-"<<obj[i].starting<<"-"<<obj[i].ending<<endl;
      }*/

    int p=0;
    cout<< "Selected activity is: "<<endl;
    cout<< obj[p].starting<< " - "<<obj[p].ending<<endl;


    for(int k=1;k<n;k++)
    {
        if(obj[k].starting>=obj[p].ending)
        {
            cout<< obj[k].starting << " - "<<obj[k].ending<<endl;
            p=k;
        }
    }


    return 0;
}
