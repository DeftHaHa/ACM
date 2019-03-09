#include<iostream>
#include<cstring>
#include<stack>
#include<cstdio>
using namespace std;
int main()
{
	int ans=0;cout<<(1<<30)<<endl;
	for(int i=0;i< (1<<30);i++)
	{
		
		int cnt=0;
		bool flag=true;
		for(int j=0;j<30;j++)
		{
			if(i>>j&1)
			{
				cnt++;
			}
			else
			{
				cnt--;
				if(cnt<0)
				{
					flag=false;
					break;
				}
			}
		}
		if(flag&&!cnt)
		{
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
