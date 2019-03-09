#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int main()
{
	int a,b;
	char s[10];
	memset(s,0,sizeof(s));
	while(cin>>a>>b)
	{
		int c=a+b;
		sprintf(s,"%d",c);
		int l=strlen(s);
		int flag=l%3;
		if(flag==0) flag=3;
		int i;
		if(s[0]=='-') {i=1;cout<<'-';}
		else i=0;
		for(;i<strlen(s);i++)
		{
			cout<<s[i];
			if(i!=(l-1)&&(i+1)%3==flag)
				cout<<',';
			
		}
		cout<<endl;
		memset(s,0,sizeof(s));
	}
	return 0;
}