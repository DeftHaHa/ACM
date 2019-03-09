#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
	int n;
	int a[10005];
	while(cin>>n)
	{
		for(int i=0;i<n;i++)
			cin>>a[i];
		int sum=0,maxsum=-1;
		int left=0,ans1=0,ans2=n-1;
		for(int i=0;i<n;i++)
		{
			sum+=a[i];
			if(sum>maxsum)
			{
				maxsum=sum;
				ans1=left;
				ans2=i;
			}
			else if(sum<0)
			{
				sum=0;
				left=i+1;
			}
		}
		if(maxsum<0)
		{
			maxsum=0;
			ans1=0;
			ans2=n-1;
		}
		cout<<maxsum<<' '<<a[ans1]<<' '<<a[ans2]<<endl;
	}
	return 0;
}