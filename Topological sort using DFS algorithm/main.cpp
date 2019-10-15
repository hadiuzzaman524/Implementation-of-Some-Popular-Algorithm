#include <iostream>
#include <queue>
#include <iterator>
#include <vector>
#include <stack>
using namespace std;


void topological_sort(int s,bool visited[],vector<int>v[],stack<int>&st )
{
    if( visited[s]==false )
    {

        visited[s]=true;

        for( int i=0;i<v[s].size();i++ )
        {
            int m=v[s][i];
            if( visited[m]==false )
            {
                topological_sort( m,visited,v,st);
            }

        }

    }
    st.push(s);


}


int main()
{
   // freopen("input.txt","r",stdin);
    int node,edge;
    cin>>node>>edge;

    vector<int>v[node+1];


    for(int i=0;i<edge;i++)
    {
        int u,m;
        cin>>u>>m;
        v[u].push_back(m);
    }
    stack<int>st;

    bool visited[node]={false};
    for(int i=0;i<node;i++)
    {
        if(visited[i]==false)
        {
            topological_sort(i,visited,v,st);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<< " ";
        st.pop();
    }

  return 0;
}
