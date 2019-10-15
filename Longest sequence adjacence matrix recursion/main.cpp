#include <bits/stdc++.h>

using namespace std;

#define N 5
string findlength(int mat[N][N],int i,int j)
{

   if(i<0&&j<0&&i>=N&&j>=N)
    return 0;

   string path;
   if(i>0&&mat[i-1][j]-mat[i][j]==1)
    path=findlength(mat,i-1,j);

   if(i+1<N&&mat[i+1][j]-mat[i][j]==1)
    path=findlength(mat,i+1,j);

   if(j>0&&mat[i][j-1]-mat[i][j]==1)
    path=findlength(mat,i,j-1);

    if(j+1<N&&mat[i][j+1]-mat[i][j]==1)
        path=findlength(mat,i,j+1);

    return to_string(mat[i][j])+ " - "+path;


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
	int rs=0;
	for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            string str=findlength(mat,i,j);

            int s=count(str.begin(),str.end(),'-');

            if(s>rs)
            {
                result=str;
                rs=s;

            }

        }
    }

    cout<<result.substr(0,result.length()-3)<<endl;


    return 0;
}
