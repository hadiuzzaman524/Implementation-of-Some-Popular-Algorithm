#include <iostream>

using namespace std;
int used[20],number[20];
void permutation(int at,int n)
{

    if(at==n+1)
    {
        for(int i=1; i<=n; i++)
            cout<<"     "<<number[i]<< " ";
        cout<<endl;
        return;
    }
    for(int i=1; i<=n; i++)
    {
        if(!used[i])
        {
            used[i]=1;
            number[at]=i;
            cout<<i<<"    jaman  "<<at<<endl;
            permutation(at+1,n);
            used[i]=0;

        }
    }
}
int main()
{
    permutation(1,3);
    return 0;
}
