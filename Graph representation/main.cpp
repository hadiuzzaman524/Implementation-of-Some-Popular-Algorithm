#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int v,e;
    cout<< "how many vartex ? ";
    cin>>v;
    cout<<"how many edge? ";
    cin>>e;
    vector<int>node[v];
    for(int i=0;i<e;i++)
    {
        int u,v;
        cout<<"enter e"<<i<<": ";
        cin>>u>>v;
        node[u].push_back(v);
        node[v].push_back(u);

    }
    for(int i=0;i<v;i++)
    {
        for(int j=0;j<node[i].size();j++)
        {
            cout<<node[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
