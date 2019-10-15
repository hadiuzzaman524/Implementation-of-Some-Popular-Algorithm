#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main()
{
    priority_queue <int> q;

    q.push(8);
    q.push(12);
    q.push(17);
    q.push(100);


    while(!q.empty())
    {
        cout<<q.top()<< " ";
        q.pop();
    }


	return 0;
}
