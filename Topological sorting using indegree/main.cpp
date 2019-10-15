#include <iostream>
#include <vector>
#include <iterator>
#include <queue>
using namespace std;


void topologicalsort(vector<int>v[],int n)
{
    vector<int>indegree(n,0);
    vector<int>::iterator it;

    for(int i=0;i<n;i++)
    {
        for(it=v[i].begin();it !=v[i].end(); it++)
        {
            indegree[*it]++;
        }
    }


    queue<int>q;
    vector<int>result;

    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
            q.push(i);
    }

    while(!q.empty())
    {
        int m=q.front();
        result.push_back(m);
        q.pop();
        for(it=v[m].begin(); it !=v[m].end();it++)
        {
            --indegree[*it];
            if(indegree[*it]==0)
                q.push(*it);
        }

    }
    for(int i=0;i<result.size();i++)
        cout<<result[i]<< " ";
    cout<<endl;


}

int main()
{
    freopen("input.txt","r",stdin);
   int node,edge;
   cin>>node>>edge;
   vector<int>v[node];

   for(int i=0;i<edge;i++)
   {
       int m,n;
       cin>>m>>n;
       v[m].push_back(n);
   }
   topologicalsort(v,node);

    return 0;
}
