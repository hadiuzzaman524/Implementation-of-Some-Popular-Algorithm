#include <iostream>
#include <vector>
using namespace std;
static int z=0;

void dfs(bool visited[],int s,vector<int>v[],int starting[],int finishing[])
{
    starting[s]=++z;

    if(visited[s]==false)
    {
        //cout<< s<< "    ";

        visited[s]=true;
        for(int i=0; i<v[s].size(); i++)
        {
            int m=v[s][i];
            if(visited[m]==false)
            {
                dfs(visited,m,v,starting,finishing);

            }

        }

    }

    finishing[s]=++z;
}

int main()
{
    freopen("input.txt","r",stdin);
    int node,edge;
    // cout<< "how many node and edge? ";
    cin>>node>>edge;

    vector<int>v[node];
    for(int i=0; i<edge; i++)
    {
        int m,n;
        cin>>m>>n;
        v[m].push_back(n);
    }
    bool visited[node]= {false};
    int starting[node]= {0};
    int finishing[node]= {0};


    for(int i=0; i<node; i++)
    {
        if(visited[i]==false)
        {
            dfs(visited,i,v,starting,finishing);
        }
    }


    for(int i=0; i<node; i++)
        cout<<"Node :"<<i<< " "<<starting[i]<< "-"<< finishing[i]<<endl;

    return 0;
}
