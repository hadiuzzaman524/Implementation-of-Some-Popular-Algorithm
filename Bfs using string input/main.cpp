#include <iostream>
#include <unordered_map>
#include <iterator>
#include <vector>
#include <list>
#include <queue>
using namespace std;
unordered_map<string ,list<string> >mp;

void bfs(string s,int node)
{



}
int main()
{


   int node,edge;

   cout<< "how many node and edge in the graph? ";
   cin>>node>>edge;


   for(int i=0;i<edge;i++)
   {
       cout<< "enter the edge "<< i+1<< " : ";
       string s,p;
       cin>>s>>p;

       mp[s].push_back(p);
       mp[p].push_back(s);

   }

//for printing the adjacency list ..................
cout<<endl;
  for(auto value:mp)
  {
      string vartex=value.first;
      list<string>ls=value.second;
      list<string>::iterator it;



      cout<< "["<<vartex<<"]"<< " ->";
      for(it=ls.begin(); it !=ls.end();it++)
        cout<< *it<< " ";
      cout<<endl;


  }


  cout<<endl;
  string starting;
  cout<< "enter the starting point: ";
  cin>>starting;
 bfs(starting,node);

    return 0;
}
