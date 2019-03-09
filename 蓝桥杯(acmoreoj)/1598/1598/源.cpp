#include<cstdio>
#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin>>N;
	int n[10005];
	bool vis[100005];
	int i=0;
	char ch=getchar();
	memset(vis,false,sizeof(vis));
	int ans1,ans2;
	while(N--)
	{
		string s;
		getline(cin,s);
		stringstream ss(s);
		while(ss>>n[i])
		{
			if(vis[n[i]]) ans2=n[i];
			vis[n[i]]=true;
			i++;
		};
	}
	sort(n,n+i);
	for(int j=1;j<i;j++)
	{
		if(n[j]!=n[j-1]+1)
		{
			if(n[j]!=n[j-1])
			{
				ans1=n[j]-1;
				break;
			}
		}
	}
	printf("%d %d\n",ans1,ans2);
	return 0;
}