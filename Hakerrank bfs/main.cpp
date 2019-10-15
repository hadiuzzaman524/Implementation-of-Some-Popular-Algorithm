#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<int>v[],int n,int s,int lb[])
{

    bool visited[n+1]= {false};
    queue<int>q;
    visited[s]=true;
    q.push(s);
    lb[s]=0;

    while(!q.empty())
    {
        int u=q.front();
        q.pop();

        for(int i=0; i<v[u].size(); i++)
        {
            int m=v[u][i];
            if(visited[m]==false)
            {


                lb[m]=lb[u]+1;
                visited[m]=true;
                q.push(m);

            }
        }
    }

}
    int main()
    {
        int n;
        cin>>n;
        while(n--)
        {

            int node,edge;
            cin>>node>>edge;

            vector<int>v[node];
            int lb[node];
            for(int i=0; i<node; i++)
                lb[i]=9999;
            for(int i=0; i<edge; i++)
            {
                int u,vvv;
                cin>>u>>vvv;

                v[u-1].push_back(vvv-1);
                v[vvv-1].push_back(u-1);
            }
            int source;
            cin>>source;
            bfs(v,node,source-1,lb);

            for(int i=0; i<node; i++)
            {
                if(lb[i]!=0&&lb[i]!=9999)
                {
                    cout<<lb[i]*6<<" ";
                }
                else if(lb[i]==9999)
                    cout<< "-1"<<" ";
            }
            cout<<endl;
        }
        return 0;
    }
