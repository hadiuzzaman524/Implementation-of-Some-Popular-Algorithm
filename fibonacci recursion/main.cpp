#include <iostream>

using namespace std;
int fib(int a)
{
    if(a<3)
        return 1;
    else
        return fib(a-1)+fib(a-2);
}
int main()
{
   cout<<fib(5);
    return 0;
}
