#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n,k;
	char s[105];
	while(T--)
	{
		cin>>n>>k;
		int cnt;
		for(int i = 1;i <= k;i++) printf("%c",'a'+i-1);
		int tot = 0;
		for(int i = 1;tot <= n-k-1;i++)
		{
			if(i < k) cnt = n/k-1;
			else if(i == k) cnt = n;
			else cnt = n/k;
			for(int j = 1;j <= cnt && tot<=n-k-1;j++)
			{
				printf("%c",'a'+i-1);
				tot++;
			}
		}
		cout<<endl;
	}
	return 0;
}
