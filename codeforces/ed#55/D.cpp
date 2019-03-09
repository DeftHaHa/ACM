#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	int a[505];
	int zero[505],zcnt=0;
	int sum = 0;
	cin>>n;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
		if(a[i]==1)
		{
			zero[zcnt++] = i;
		}
		sum+=a[i];
	}
	int pre = 0,zpos=0;
	int ans[505][2],cnt=0;
	if(sum<2*(n-1))
	{
		cout<<"NO"<<endl;
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(a[i]>1)
			{
				if(pre)
				{
					ans[cnt][0] = pre;
					ans[cnt][1] = i;
					cnt++;
					a[i]--;
				}
				while(a[i]>1&&zpos<zcnt-1) //a[i]>1因为剩余度数必须至少为1，否则后面接不上 
				{
					ans[cnt][0] = i;
					ans[cnt][1] = zero[zpos];
					cnt++;
					a[i]--;
					zpos++; 
				}	
				pre = i;
			}
		}
		if(zcnt)
		{
			ans[cnt][0] = pre;
			ans[cnt][1] = zero[zpos];
			cnt++;
		}
		cout<<"YES"<<' '<<min(2,zcnt)+cnt-zcnt<<endl<<cnt<<endl;
		for(int i = 0;i < cnt;i++)
		{
			printf("%d %d\n",ans[i][0],ans[i][1]);
		}
	}
	return 0;
}

