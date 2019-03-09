#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int dx[]={0,1,0,-1};
	int dy[]={1,0,-1,0};
	int dir=1;
	char s[10];
	int n;
	int x=0,y=0;
	cin>>n;
	char ch=getchar();
	int d;
	while(n--)
	{
		scanf("%s%d",s,&d);
		ch=getchar();
		if(s[0]=='f') dir=dir;
		else if(s[0]=='b') dir=(dir+2+4)%4;
		else if(s[0]=='l') dir=(dir-1+4)%4;
		else if(s[0]=='r') dir=(dir+1+4)%4;
		x+=dx[dir]*d;
		y+=dy[dir]*d;
	}
	printf("%d %d\n",x,y);
	return 0;
}
