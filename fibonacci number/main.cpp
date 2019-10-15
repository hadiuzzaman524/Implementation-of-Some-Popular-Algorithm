#include <iostream>

using namespace std;

int main()
{
    int fib[50];
    int fib1=0;
    int fib2=1;
    int fib3;
  fib[0]=fib1;
  fib[1]=fib2;
  for(int i=2;i<50;i++)
  {
      fib3=fib1+fib2;
      fib[i]=fib3;
      fib1=fib2;
      fib2=fib3;
  }
for(int a:fib)
    cout<<a<< " ";
    return 0;
}
