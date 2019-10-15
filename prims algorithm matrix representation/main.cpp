#include <iostream>
#include <cstring>
using namespace std;

#define INF 9999999

// number of vertices in grapj
#define V 5

// create a 2d array of size 5x5
//for adjacency matrix to represent graph

int G[V][V] =
{
    {0, 9, 75, 0, 0},
    {9, 0, 95, 19, 42},
    {75, 95, 0, 51, 66},
    {0, 19, 51, 0, 31},
    {0, 42, 66, 31, 0}
};

int main ()
{
  int visited[V]={false};
  int n=0;
  visited[0]=true;
  int x,y;
  while(n<V-1)
  { int min=9999;
      for(int i=0;i<V;i++)
      {
          if(visited[i])
          {
              for(int j=0;j<V;j++)
              {
                  if(!visited[j]&&G[i][j])
                  { if(min>G[i][j])
                    {
                        min=G[i][j];
                        x=i;
                        y=j;
                    }

                  }
              }
          }
      }
      cout<<x<< "-"<<y<<":"<<G[x][y]<<endl;
      visited[y]=true;
      n++;

  }

    return 0;
}
