#include <iostream>
#include <vector>
#include <queue>
#define white 0
#define black 1
#define red 2
using namespace std;

vector <int>v[10];
bool bicolor(int source,int n)
{
    queue <int> q;
    q.push(source);
    int color[n]= {white};
    color[source]=red;
    while(!q.empty())
    {
        int u=q.front();
q.pop();
        for(int i=0; i<v[u].size(); i++)
        {
            int m=v[u][i];
            if(color[m]==white)
            {
                if(color[u]==red)
                {
                    color[m]=black;
                }
                else
                    color[m]=red;
                q.push(m);
            }
            if(color[m]==color[u])
                return false;
        }

    }
    return true;
}

int main()
{
    v[1].push_back(2);
    v[1].push_back(3);
    v[1].push_back(5);

    v[2].push_back(1);
    v[2].push_back(4);
    v[2].push_back(5);

    v[3].push_back(1);
    v[3].push_back(4);
    v[3].push_back(5);

    v[4].push_back(2);
    v[4].push_back(3);

    v[5].push_back(2);
    v[5].push_back(3);

    cout<<"the adjacency list is: "<<endl;
    for(int i=0;i<=5;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            cout<<v[i][j]<< " ";
        }
        cout<<endl;
    }

    bool color=bicolor(1,5);
    if(color==true)
        cout<<"the graph is bicoloring"<<endl;
    else
        cout<< "the graph is not bicoloring"<<endl;

    return 0;
}
