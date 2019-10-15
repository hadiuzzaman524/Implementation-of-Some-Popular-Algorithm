#include <iostream>
using namespace std;


int main()
{
    int n;
    cout<< "how many element: ";
    cin>>n;
    int wt[n+1],prof[n+1];
    wt[0]=0,prof[0]=0;
    cout<< "enter the element: ";
    for(int i=1; i<=n; i++)
    {
        cin>>wt[i]>>prof[i];
    }
    for(int i=0; i<=n; i++)
    {
        cout<< wt[i]<< " - "<<prof[i]<<endl;
    }
    int s;
    cout<<"enter the knapsack size: ";
    cin>>s;
    int table[n+1][s+1];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            if(i==0||j==0)
            {
                table[i][j]=0;
            }
            else if(wt[i]>j)//be careful else if not if
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                int lave,take;
                lave=table[i-1][j];
                take=table[i-1][j-wt[i]]+prof[i];
                table[i][j]=max(lave,take);
            }
        }
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=s; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl<<endl;
    cout<< "maximum profit is: "<< table[n][s]<<endl;
    cout<<endl;
    int i=n, j=s;


    while(i>0&&j>0)
    {
        if(table[i][j] !=table[i-1][j])
        {
            cout<< i<< " ";

            j=j-wt[i];
            i--;
        }
        else
            i--;
    }
    return 0;

}
