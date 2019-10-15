#include <iostream>

using namespace std;

#define m 4
#define n 5


int findmat(int mat[m][n])
{
    int table[m+1][n+1];

    for(int i=0; i<=m; i++)
        table[i][0]=0;
    for(int i=0; i<=n; i++)
        table[0][i]=0;


    int maximum=0;
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            //table[i][j]=mat[i][j];

            if(mat[i-1][j-1]==0)
            {
                table[i][j]=0;

            }
            else
            {
                table[i][j]= min(min(table[i-1][j-1],table[i][j-1]),table[i-1][j])+1;
                maximum=max(table[i][j],maximum);
            }


        }
    }

    for(int i=0; i<=m; i++)
    {
        for(int j=0; j<=n; j++)
        {
            cout<<table[i][j]<< " ";
        }
        cout<<endl;
    }
    cout<<endl;
    return maximum;

}
int main()
{
    int mat[m][n]=
    {
        {0,0,1,1,1},
        {1,0,1,1,1},
        {0,1,1,1,1},
        {1,0,1,1,1},
        /* { 0, 0, 1, 0, 1, 1 },
         { 0, 1, 1, 1, 0, 0 },
         { 0, 0, 1, 1, 1, 1 },
         { 1, 1, 0, 1, 1, 1 },
         { 1, 1, 1, 1, 1, 1 },
         { 1, 1, 0, 1, 1, 1 },
         { 1, 0, 1, 1, 1, 1 },
         { 1, 1, 1, 0, 1, 1 }*/
    };

    int z=findmat(mat);

    cout<<z<<endl;
    return 0;
}
