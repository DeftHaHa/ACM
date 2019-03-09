#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int x1,y1,x2,y2,x3,y3,x4,y4;
	while(T--)
	{
		scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4);
		if(x1>x2) swap(x1,x2);
		if(y1>y2) swap(y1,y2);
		if(x3>x4) swap(x3,x4);
		if(y3>y4) swap(y3,y4);
		int lx=max(x1,x3),ly=max(y1,y3);
		int rx=min(x2,x4),ry=min(y2,y4);
		if(lx>rx||ly>ry) printf("Miss\n");
		else printf("Hit\n");
	}
	return 0;
}
