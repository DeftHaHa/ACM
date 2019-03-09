#include<iostream>
using namespace std;
int main()
{
        long long fib[94];
        fib[1]=1;
        fib[2]=2;
        for(int i=3;i<94;i++)
        {
                fib[i]=fib[i-1]+fib[i-2];
                cout<<i<<' '<<fib[i]<<endl;
        }

        return 0;
}
