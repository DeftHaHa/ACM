#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int c[1000005],h[1000005];
int lowbit(int x)
{
	return x&-x;
}
void insert(int pos,int num)
{
	for(int i=pos;i<=1000001;i+=lowbit(i))
	{
		c[i]+=num;
	}
}
int getsum(int pos)
{
	int ans=0;
	for(int i=pos;i>0;i-=lowbit(i)) ans+=c[i];
	return ans;
}
int tot[1000005];
long long jc[1000005];
int main()
{
	int N;
	memset(c,0,sizeof(c));
	memset(tot,0,sizeof(tot));
	cin>>N;
	jc[1]=1;
	for(int i=2;i<=1000000;i++) jc[i]=jc[i-1]+i; 
	long long ans=0;
	for(int i=0;i<N;i++)
	{
		scanf("%d",&h[i]);
		insert(h[i]+1,1);     //身高可为0
		tot[i]+=i+1-getsum(h[i]+1);
	}
	memset(c,0,sizeof(c));
	for(int i=N-1;i>=0;i--)
	{
		insert(h[i]+1,1);
		tot[i]+=getsum(h[i]); 
	}
	for(int i=0;i<N;i++) ans+=jc[tot[i]];
	cout<<ans<<endl;
	return 0;
}
