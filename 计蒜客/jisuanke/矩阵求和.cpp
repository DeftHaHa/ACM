#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int main()
{
	long long n[105][105];
	long long num=0;
	int maxn=101;
	for(int i=1;i<=maxn;i++)
		for(int j=1;j<=maxn;j++)
			n[i][j]=++num;
		
	int ans=0;

	int mid=maxn/2+1;
	for(int i=1;i<=mid;i++)
	{
		ans+=n[i][mid];  
		for(int j=1;j<=i-1;j++)
		{    //cout<<n[i][mid-j]<<' '<<n[i][mid+j]<<endl;
			ans+=n[i][mid-j]+n[i][mid+j];
		}
	}
	for(int i=mid+1;i<=maxn;i++)
	{
		ans+=n[i][mid];  
		for(int j=1;j<=maxn-i;j++)
		{
			ans+=n[i][mid-j]+n[i][mid+j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
