#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <iterator>
using namespace std;
void topsort(vector<int>G[],int vertex)
{
   /* for(int i=1; i<=vertex; i++)
    {
        for(int j=0; j<G[i].size(); j++)
            cout<<G[i][j]<< " ";
        cout<<endl;
    }
    cout<<endl;*/

    vector<int>indegree(vertex+1,0);
    vector<int>::iterator it;
    for(int i=1; i<=vertex; i++)
    {
        for(it=G[i].begin(); it!=G[i].end(); it++)
        {
            indegree[*it]++;
        }
    }
   /* for(it=indegree.begin()+1; it !=indegree.end(); it++)
        cout<<*it<<endl;*/
    queue<int>q;
    for(int i=1;i<=vertex;i++)// 1 because vertex will be start 1 not 0
    {
        if(indegree[i]==0)
            q.push(i);
    }
  vector<int>result;
    while(!q.empty())
    {
       int x=q.front();
       result.push_back(x);
       q.pop();
       for(it=G[x].begin(); it !=G[x].end();it++)
       {
           --indegree[*it];
           if(indegree[*it]==0)
            q.push(*it);
       }
    }
    cout<<"the topological sort result is: "<<endl;
    for(int i=0;i<vertex;i++)
        cout<<result[i]<<"->";
    cout<<endl;



}

int main()
{
    freopen("input.txt","r",stdin);
    int vertex,edge;
    cin>>vertex>>edge;
    vector<int>G[edge+1];

    for(int i=0; i<edge; i++)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    topsort(G,vertex);


    return 0;
}

