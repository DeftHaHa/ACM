#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
bool is_prime(long long n)
{
        long long i;
        for(i=2;i<=sqrt(n);i++)\
        {
                if(n%i==0) break;
        }
        if(i>sqrt(n)) return true;
        else return false;
}
int main()
{
        long long n;
        while(cin>>n)
        {
                if(n==0) cout<<0<<endl;
                else if(n==2) cout<<1<<endl;
                else if(n&1)
                {
                        if(is_prime(n)) cout<<1<<endl;
                        else
                        {
                                if(is_prime(n-2)) cout<<2<<endl;
                                else cout<<3<<endl;
                        }
                }
                else
                        cout<<2<<endl;
        }
        return 0;
}
