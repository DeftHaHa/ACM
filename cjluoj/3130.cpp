#include<iostream>
using namespace std;
int main()
{
        int fib[45];
        fib[1]=1;
        fib[2]=1;
        for(int i=3;i<=40;i++)
        {
                fib[i]=fib[i-1]+fib[i-2];
        }
        int n;
        while(cin>>n)
        {
                cout<<fib[n]<<endl;
        }
        return 0;
}
