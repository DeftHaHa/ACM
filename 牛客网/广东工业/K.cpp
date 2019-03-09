#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	char s[100005];
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(s,0,sizeof(s));
		scanf("%s",s);
		int l=strlen(s);
		for(int i=1;i<=n;i++)
		{
			int pos=i;
			int a=2*n-2*i;
			int b=2*i-2;
			printf("%c",s[pos-1]);
			while(pos<=l)
			{
				pos+=a;
				if(pos<=l&&a!=0) printf("%c",s[pos-1]);
				pos+=b;
				if(pos<=l&&b!=0) printf("%c",s[pos-1]);
			}
		}
		cout<<endl;
	}
	return 0;
}
