#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct
{
    float waight;
    float profit;
    float rat;

} Knapsack;

bool comp(Knapsack ob1,Knapsack ob2)
{
    if(ob1.rat !=ob2.rat)
        return ob1.rat>ob2.rat;
}
int main()
{
    int n;
    cout<< "how many element? ";
    cin>>n;
    int sum;
    cout<< "enter the knapsack size: ";
    cin>>sum;
    Knapsack obj[n];


    for(int i=0; i<n; i++)
    {
        cin>>obj[i].waight;
        cin>>obj[i].profit;
        obj[i].rat=(float)obj[i].profit/obj[i].waight ;
    }
    sort(obj,obj+n,comp);
    cout<< "sorted list is: "<<endl;
    for(int i=0; i<n; i++)
    {
        cout<< obj[i].waight<< "    "<<obj[i].profit<< "   "<<obj[i].rat<<endl;
    }

   float total_w=0;
   float total_profit=0;


    for(int i=0; i<n; i++)
    {
        if(obj[i].waight+total_w<=sum)
        {
            total_w+=obj[i].waight;
            total_profit+=obj[i].profit;
        }
        else
        {
            float w=(sum-total_w);
            float value=w*(float)obj[i].profit/obj[i].waight ;
            total_w+=w;
            total_profit+=value;
            break;
        }
    }

    cout<<"total profit is: "<<total_profit<<" total weight is: "<<total_w<<endl;


    return 0;
}
