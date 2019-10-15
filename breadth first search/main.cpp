#include<iostream>
#include<vector>
#include <queue>
using namespace std;

void bfs(vector<int>v[],int source,int n)
{
    queue<int>q;
    bool visited[n+1]= {false};
    visited[source]=true;
    q.push(source);


    cout<< "the breadth first search result is: ";
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        cout<< u<< " ";
        for(int i=0; i<v[u].size(); i++)
        {
            int m=v[u][i];
            if(visited[m]==false)
            {
                visited[m]=true;
                q.push(m);
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
        node[b].push_back(a);

    }

    bfs(node,0,n);


    return 0;
}
