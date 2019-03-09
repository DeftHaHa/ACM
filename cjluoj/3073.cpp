#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
int getPermuStack(int n, int m)
{
        if(n == 0)
        return 1;
        if(m == 0)
        return getPermuStack(n-1, 1);
        return getPermuStack(n, m-1) + getPermuStack(n-1, m+1);
}
int main()
{

        int n;
        while(cin>>n)
        {
                cout<<getPermuStack(n, 0)<<endl;
        }
        return 0;
}
