#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int n,x,y,d;
	while(t--)
	{
		scanf("%d%d%d%d",&n,&x,&y,&d);
		bool Find = false;
		if((x-y)%d == 0)
		{
			cout<<abs(x-y)/d<<endl;
			Find = true;
		}
		else
		{
			int ans1,ans2;
			ans1 = ans2 = 0x3f3f3f3f;
			if((y-1)%d==0)
			{
				ans1 = (x-1)/d;
				if((x-1)%d>0) ans1++;
				Find = true;
				ans1 += (y-1)/d;
			}
			if((n-y)%d==0)
			{
				ans2 = (n-x)/d;
				if((n-x)%d>0) ans2++;
				ans2 += (n-y)/d;
				Find = true;
			}
			if(Find) cout<<min(ans1,ans2)<<endl;
		} 
		if(!Find) cout<<-1<<endl;
		
	}
	return 0;
}
