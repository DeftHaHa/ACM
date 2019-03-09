#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int colcnt[20];
int col[100005];
int main()
{
	memset(colcnt,0,sizeof(colcnt));
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&col[i]);
	}
	int tot=0;
	int ans=n;
	for(int l=0,r=0;r<n;)
	{
		while(tot<m&&r<n)  //ÓÒÀ© 
		{
			if(!colcnt[col[r]]) tot++;
			colcnt[col[r]]++;
			r++;
		}
		ans=min(r-l,ans);
		while(tot==m&&l<r)
		{
			if(colcnt[col[l]]==1) tot--;
			else
			{ 	
				ans=min(r-l-1,ans);
			}
			colcnt[col[l]]--;
			l++;
		}	
	}
	cout<<ans<<endl;
	return 0;
}
