#include <iostream>
#include <vector>
using namespace std;


void dfs(bool visited[],vector<int>node[],int source)
{
    if(visited[source]==false)
    {
        cout<<source<< " ";
        visited[source]=true;

        for(int i=0;i<node[source].size();i++)
        {
            int m=node[source][i];
            if(visited[m]==false)
            {
                dfs(visited,node,m);
            }
        }
    }


}

int main()
{
    int n,e;
    cout<< "how many vertex: ";
    cin>>n;
    cout<< "how many edge: ";
    cin>>e;

    vector<int>node[n];

    for(int i=0; i<e; i++)
    {
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
      //  node[b].push_back(a);

    }
    bool visited[n+1]={false};


    for(int i=0;i<n;i++)
    {
        if(visited[i]==false)
        {
            dfs(visited,node,i);
        }
    }



}
