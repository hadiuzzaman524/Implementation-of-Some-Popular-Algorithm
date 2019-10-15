#include <iostream>
#define inf 99999
using namespace std;
int s[50][50];
void print(int i,int j)
{
    if(i==j)
    {
        cout<< "A"<<i;
    }
    else
    {
        cout<< "(";
        print(i,s[i][j]);
        print(s[i][j]+1,j);
        cout<<")";
    }
}
int main()
{
    int n;
    cout<< "how many matrix: ";
    cin>>n;
    int d[n+1];
    bool flag=true;

    for(int i=0; i<n; i++)
    {
        cout<< "enter the dimention of matrix: ";
        int d1,d2;
        cin>>d1>>d2;
        if(i==0)
        {
            d[0]=d1;
            d[1]=d2;
        }
        else
        {
            if(d[i] !=d1)
                flag=false;
            else
                d[i+1]=d2;
        }
    }
    if(flag==false)
    {
        cout<< "multiplication can not posible. "<<endl;
    }

    for(int i=0; i<n; i++)
    {
       for(int j=0; j<n; j++)
       {
           s[i][j]=-1;
       }
    }
    int N[n][n];
    for(int i=0;i<n;i++)
    {
        N[i][i]=0;
    }
    for(int l=1; l<n;l++)
    {
        for(int i=0;i<n-l;i++)
        {
            int j=l+i;
            N[i][j]=inf;
            for(int k=0; k<j;k++)
            {
                int cost=N[i][k]+N[k+1][j]+d[i]*d[k+1]*d[j+1];
                if(cost<N[i][j])
                {
                    N[i][j]=cost;
                    s[i][j]=k;
                }
            }
        }
    }
    print(0,n-1);
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< N[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<< s[i][j]<< " ";
        }
        cout<<endl;
    }*/
    return 0;
}
