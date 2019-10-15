#include <iostream>

using namespace std;
#define M 4
#define N 4
int totalpath(int mat[M][N],int m,int n,int cost)
{
    if(cost<0)
        return 0;
    if(m==0&&n==0)
    {
        if(mat[0][0]-cost==0)
            return 1;
        else
            return 0;
    }


    if(m==0)
    {
        return totalpath(mat,0,n-1,cost-mat[m][n]);
    }


    if(n==0)
    {
        return totalpath(mat,m-1,0,cost-mat[m][n]);
    }

    return totalpath(mat,m-1,n,cost-mat[m][n])+totalpath(mat,m,n-1,cost-mat[m][n]);
}
int main()
{
    int mat[M][N] =
    {
        { 4, 7, 1, 6 },
        { 5, 7, 3, 9 },
        { 3, 2, 1, 2 },
        { 7, 1, 6, 3 }
    };

    int cost = 25;
    cout<<"total number of the path is: "<<totalpath(mat,M-1,N-1,cost)<<endl;
    return 0;
}
