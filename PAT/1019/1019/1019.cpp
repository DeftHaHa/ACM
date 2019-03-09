#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int N,B;
	int s[55];
	while(cin>>N>>B)
	{
		if(N==0)
		{
			cout<<"Yes"<<endl<<0<<endl;
			continue;
		}
		int tot=0;
		while(N>0)
		{
			s[++tot]=N%B;
			N/=B;
		}
		bool flag=true;
		for(int i=1,j=tot;i<=j;i++,j--)
		{
			if(s[i]!=s[j])
			{
				flag=false;
				break;
			}
		}
		if(flag) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
		cout<<s[tot];
		for(int i=tot-1;i>=1;i--) cout<<' '<<s[i];
		cout<<endl;
	}
	return 0;
}