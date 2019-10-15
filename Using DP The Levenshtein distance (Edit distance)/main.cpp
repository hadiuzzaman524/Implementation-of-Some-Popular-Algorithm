#include <iostream>

using namespace std;
int dis(string x,string y,int m,int n)
{
    int table[m+1][n+1]= {0};
    for(int i=0; i<=m; i++)
        table[i][0]=i;
    for(int j=0; j<=n; j++)
        table[0][j]=j;
        int cost;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(x[i-1]==y[j-1])
            {
                cost=0;
            }
            else
                cost=1;

            table[i][j]=min(min(table[i-1][j]+1,table[i][j-1]+1),table[i-1][j-1]+cost);

        }
    }
    return table[m][n];

}

int main()
{

    string x="kitten";
    string y="sitting";
    int m=x.length();
    int n=y.length();

    int z=dis(x,y,m,n);
    cout<< "total operation is: "<<z<<endl;
    return 0;
}
