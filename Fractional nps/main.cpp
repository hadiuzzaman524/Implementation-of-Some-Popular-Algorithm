#include <iostream>
#include <algorithm>
using namespace std;
class Knapsack
{
public:
    float weight,profit,rat;
    void set(float w,float p)
    {
        weight=w;
        profit=p;
        rat=(float)profit/weight;
    }
};
bool comp(Knapsack k1,Knapsack k2)
{
    if(k1.rat!=k2.rat)
        return k1.rat>k2.rat;
}
int main()
{
   int n;
   cout<< "how many element? ";
   cin>>n;
   Knapsack obj[n];
   float capacity;
   cout<< "enter the total capacity of knapsack : ";
   cin>>capacity;


   for(int i=0;i<n;i++)
   { cout<< "enter the weight and profit of element "<<i+1<< ": ";
       float b,c;
       cin>>b>>c;
      obj[i].set(b,c);
   }
   cout<< endl;


   sort(obj,obj+n,comp);


   float total_profit=0,total_waight=0;


   for(int i=0;i<n;i++)
   {
       if(total_waight+obj[i].weight<=capacity)
       {
           total_profit+=obj[i].profit;
           total_waight+=obj[i].weight;
       }
       else
       {
           float w=capacity-total_waight;
           float p=w*(float)obj[i].profit/obj[i].weight;
           total_waight+=w;
           total_profit+=p;
           break;
       }

   }


   cout<< "total profit is: "<<total_profit<< "\ntotal weight of knapsack is: "<<total_waight<<endl;

    return 0;
}
