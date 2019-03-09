#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct NUM
{
	int cnt,v;
}num[200005];
int R = 0;
int t,k;
bool cmp(NUM a,NUM b)
{
	return a.cnt > b.cnt;
}
bool check(int n)
{
	int tot = 0;
	for(int i = 1;i <= R;i++)
	{
		tot += num[i].cnt/n;
		if(tot >= k) return true;
	}
	return false;
}
int main()
{
   
	int x;
	for(int i = 0;i <= 200000;i++)
	{
		num[i].v = i;
		num[i].cnt = 0;
	}
	scanf("%d%d",&t,&k);
	for(int i = 0;i < t;i++)
	{
		scanf("%d",&x);
		num[x].cnt++;
	}
	for(int i = 1;i <= 200000;i++)
	{ 
		if(num[i].cnt)
		{
			num[++R] = num[i];
		} 
	}
	sort(num+1,num+R+1,cmp);
	int l = 1,r = 200000;//attention!!!!
	while(l<r)
	{
		int mid = (l+r+1)/2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}
	int ans[200005],ansCnt = 0;
	for(int i = 1;i<=R&&ansCnt<k;i++)
	{ 
		for(int j = 0;j < num[i].cnt/r&&ansCnt<k;j++)
		{
			ans[ansCnt++] = num[i].v;
		}
	}
	for(int i = 0;i < k;i++)
	{
		printf("%d",ans[i]);
		if(i!=k-1) printf(" ");
	}



    return 0;
}
