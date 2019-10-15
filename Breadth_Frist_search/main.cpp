#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void bfs(vector<int>v[],int node,int source)
{
    bool visited[node+1]={false};

    queue<int>  q;

    q.push(source);
    visited[source]=true;

    while(!q.empty())
    {
        int u=q.front();
        cout<<u<< " ";
        q.pop();

        for(int i=0;i<v[u].size();i++)
        {
            int m=v[u][i];
            if(!visited[m])
            {
                q.push(m);
                visited[m]=true;
            }
        }


    }

}


int main()
{
   int node;
   cout<<"how many node?";
   cin>>node;

   int edge;
   cout<<"how many edge? ";
   cin>>edge;

   vector<int>list[node];

   for(int i=0;i<edge;i++)
   {
       int m,n;
       cout<<"enter edge"<<i+1<<" :";
       cin>>m>>n;
       list[m].push_back(n);
       list[n].push_back(m);
   }

   bfs(list,node,0);

    return 0;
}
