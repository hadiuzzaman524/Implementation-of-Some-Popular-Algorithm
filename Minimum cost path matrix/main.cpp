#include <iostream>
#include <vector>
using namespace std;
#define m 3
#define n 4
int print(int mat[m][n])
{


    int table[m][n];
    table[0][0]=mat[0][0];

    for(int i=1; i<m; i++)
    {
        table[i][0]=mat[i][0]+table[i-1][0];
    }

    for(int i=1; i<n; i++)
    {
        table[0][i]=mat[0][i]+table[0][i-1];
    }

    for(int i=1;i<m;i++)
    {
        for(int j=1;j<n;j++)
        {
            table[i][j]=min(table[i-1][j],table[i][j-1])+mat[i][j];
        }
    }

    for(int i=0; i<m; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;

    //find the path

    int i=m-1;
    int j=n-1;
    while(i>=0&&j>=0)
    {
       if(table[i][j]==table[i-1][j]+mat[i][j])
       {
         cout<<mat[i][j]<< " ";
           i--;

       }
       else if(table[i][j]==table[i][j-1]+mat[i][j])
       {
         cout<<mat[i][j]<< " ";
           j--;
       }
       else
       {
           cout<<mat[i][j]<< " ";
           i--;
           j--;
       }
    }

    cout<<endl;

    return table[m-1][n-1];
}
int main()
{
    int mat[m][n]=
    {
        {1,3,5,8},
        {4,2,1,7},
        {4,3,2,3}

       /* { 4, 7, 8, 6, 4 },
		{ 6, 7, 3, 9, 2 },
		{ 3, 8, 1, 2, 4 },
		{ 7, 1, 7, 3, 7 },
		{ 2, 9, 8, 9, 3 }*/

    };
    cout<< "the minimum cost is: "<< print(mat)<<endl;
    return 0;
}
