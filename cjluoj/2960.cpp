#include<iostream>
#include<cmath>
using namespace std;
bool prime(int n)
{
        int i;
        for(i=2;i<=sqrt(n);i++)
                if(n%i==0) break;
        if(i>sqrt(n)) return true;
        else return false;
}
int main()
{
        int n,i;
        while(cin>>n)
        {
                for(i=2;i<=n;i++)
                {
                        if(prime(i))
                        {
                                if(prime(n-i)) break;
                        }
                }
                cout<<i<<' '<<n-i<<endl;
        }
        return 0;
}
