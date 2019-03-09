#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int a[100005];
	int n;
	cin>>n;
	for(int i = 1;i <= n;i++) scanf("%d",&a[i]);
	int pos = 0;
	bool up = 0;
	for(int i = 2;i<=n;i++)
	{
		if(a[i]<a[j])
		{
			if(up==-1)
			{
				pos = i;
				break;
			}
			up = 1; 
		}
		else if(a[i]>a[j])
		{
			if(up==1)
			{
				pos = i;
				break;
			}
			up = -1;
		}
	}
	if(pos>5)
	{
		cout<<-1<<endl;
	}
	else
	{
		int s;
		if(up==1) 
		for(int i = pos;i <= n;i++)
		{
			if(a[i]<a[j])
			{
				if(up==-1)
				{
					if(i-pos+1>5)
					pos = i;
				}
				s++;
			}
			else if(a[i]>a[j])
			{
				if(up==1)
				{
					if(i-pos+1>5)
					pos = i;
				}
				up = -1;
				s--;
			}
		}
	}
	return 0;
}
