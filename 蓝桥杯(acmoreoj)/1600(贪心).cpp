#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	//freopen("DATA.txt","r",stdin);
	int N,n[50005];
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&n[i]);
	int ans=N;
	for(int i=0;i<N;i++)
	{
		int l=n[i],r=n[i];
		for(int j=i+1;j<N;j++)
		{
			l=min(l,n[j]);
			r=max(r,n[j]);
			if(r-l==j-i) ans++;
		}
	}
	cout<<ans<<endl;
} 
