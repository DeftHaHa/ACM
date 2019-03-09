#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int cnt[1000005];
int main()
{
	int T,n,m;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		memset(cnt,0,sizeof(cnt));
		int a;
		for(int i = 0;i < n;i++)
		{
			scanf("%d",&a);
			cnt[a]++;
		}
		for(int GCD = 1000000;GCD >= 1;GCD--)
		{
			int tot = 0;
			for(int j = GCD;j <= 1000000;j+=GCD)
			{
				tot += cnt[j];
			}
			if(tot >= m)
			{
				cout<<GCD<<endl;
				break;
			}
		}
	}
	return 0;
}
