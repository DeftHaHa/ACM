#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int mod=998244353;
bool flag;
int getPermuStack(int n, int m)
{
        if(n == 0)
        {
				return 1;
		}
        if(m == 0)
        return getPermuStack(n-1, 1);
        return getPermuStack(n, m-1) + getPermuStack(n-1, m+1);
}
int main()
{
	int T,c=0;
	cin>>T;
	int n;
	while(T--)
	{
		scanf("%d",&n);
		flag=true;
		printf("Case: #%d: %lld\n",++c,getPermuStack(n,0));
	}
	return 0;
}



