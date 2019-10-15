#include <iostream>
#include <unordered_map>
#include <string>
#define N 5
#include <algorithm>

using namespace std;

string findpath(int mat[N][N],int i,int j)
{
    if(i<0&&j<0&&i>=N&&j>=N)
        return 0;
    string path;
    unordered_map<string,string>mp;
   string key=to_string(i)+"|"+to_string(j);

    if(mp.find(key)==mp.end())
    {
        if(i>0&&mat[i-1][j]-mat[i][j]==1)//up
        {
            path=findpath(mat,i-1,j);
        }
        if(i+1<N&&mat[i+1][j]-mat[i][j]==1)//down
        {
            path=findpath(mat,i+1,j);
        }
        if(j>0&&mat[i][j-1]-mat[i][j]==1) //left
        {
            path=findpath(mat,i,j-1);
        }
        if(j+1<N&&mat[i][j+1]-mat[i][j]==1)//right
        {
            path=findpath(mat,i,j+1);
        }
        mp[key]=to_string(mat[i][j])+" - "+path;
    }
    return mp[key];
}

int main()
{
   	int mat[N][N] =
	{
		{ 10, 13, 14, 21, 23 },
		{ 11,  9, 22,  2,  3 },
		{ 12,  8,  1,  5,  4 },
		{ 15, 24,  7,  6, 20 },
		{ 16, 17, 18, 19, 25 }
	};
	string result;
	int len=0;
	for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            string str=findpath(mat,i,j);
            int s=count(str.begin(),str.end(),'-');
            if(s>len)
            {
                result=str;
                len=s;
            }
        }
    }
    cout<<"the path is: ";
    cout<<result.substr(0,result.length()-3)<<endl;

    return 0;
}
