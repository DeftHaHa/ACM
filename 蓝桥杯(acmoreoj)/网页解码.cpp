#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int main()
{
//	freopen("DATA.txt","r",stdin);
	char ch;
	int ans=0;
	while(scanf("%c",&ch)!=EOF)
	{  //cout<<ch;
		if(ch>='0'&&ch<='9')
		{
			int temp;
			temp=ch-'0';
			while(1)
			{
				scanf("%c",&ch);
				if(ch>='0'&&ch<='9')
				{
					temp=temp*10+(ch-'0');
				}
				else
				{
					ans+=temp; cout<<ans<<endl;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
