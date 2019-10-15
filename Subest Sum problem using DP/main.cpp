#include <iostream>

using namespace std;
bool subsetSum(int ar[],int n,int sum)
{
    int table[n+1][sum+1];

    //item will be zero and the sum is not zero thats why it is false
    for(int i=1; i<=sum;i++)
        table[0][i]=false;

    //sum will be zero and item are remaining means we will get the sum
    for(int i=0;i<=n;i++)
        table[i][0]=true;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
            if(ar[i-1]>j)
            {
                table[i][j]=table[i-1][j];
            }
            else
            {
                table[i][j]=table[i-1][j]||table[i-1][j-ar[i-1]];
            }
        }
    }

    return table[n][sum];


}
int main()
{
    int arr[] = { 7, 3, 2, 5, 8 };
    int sum = 18;


    int n = sizeof(arr) / sizeof(arr[0]);

    if (subsetSum(arr, n, sum))
        cout << "Yes";
    else
        cout << "No";


    return 0;
}
