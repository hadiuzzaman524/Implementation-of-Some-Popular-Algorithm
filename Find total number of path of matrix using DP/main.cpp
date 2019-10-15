#include <iostream>
#include <unordered_map>
#include <string>
#define M 4
#define N 4
using namespace std;
int totalpath(int mat[M][N],int m,int n,int cost)
{
    if(cost<0)
        return 0;
    if(m==0&&n==0)
    {
        if(cost-mat[0][0]==0)
            return 1;
        else
            return 0;

    }
    unordered_map<string ,int>mp;

    string key=to_string(m)+"|"+to_string(n)+to_string(cost);

    if(mp.find(key)==mp.end())
    {
        if(m==0)
            mp[key]=totalpath(mat,0,n-1,cost-mat[m][n]);

        if(n==0)
            mp[key]=totalpath(mat,m,0,cost-mat[m][n]);

        mp[key]=totalpath(mat,m-1,n,cost-mat[m][n])+totalpath(mat,m,n-1,cost-mat[m][n]);
    }
  return mp[key];
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
