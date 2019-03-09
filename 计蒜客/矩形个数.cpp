#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct xxx
{
	int x1,x2,y1,y2;
}xx[305];
struct yyy
{
	int x1,x2,y1,y2;
}yy[305];
int main()
{
	
	int x1,y1,x2,y2;
	int n;
	cin>>n;
	int cntx=0,cnty=0;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		if(x1==x2)
		{
			yy[cnty].x1=x1;
			yy[cnty].x2=x2;
			yy[cnty].y1=y1;
			yy[cnty++].y2=y2;
		}
		else if(y1==y2)
		{
			xx[cntx].x1=x1;
			xx[cntx].x2=x2;
			xx[cntx].y1=y1;
			xx[cntx++].y2=y2;
		}
	}
	int ans=0;
	for(int i=0;i<cnty-1;i++)
	{
		for(int j=i+1;j<cnty;j++)
		{       
			//printf("yy:%d %d %d %d & %d %d %d %d\n",yy[i].x1,yy[i].y1,yy[i].x2,yy[i].y2,yy[j].x1,yy[j].y1,yy[j].x2,yy[j].y2);
			int maxy_i=max(yy[i].y1,yy[i].y2),miny_i=min(yy[i].y1,yy[i].y2);
			int maxy_j=max(yy[j].y1,yy[j].y2),miny_j=min(yy[j].y1,yy[j].y2);
			if((maxy_i>=maxy_j&&miny_i<maxy_j)||(maxy_i<maxy_j&&maxy_i>miny_j))
			{
				int a[4]={yy[i].y1,yy[i].y2,yy[j].y1,yy[j].y2};
				sort(a,a+4);
				int temp=0;
				int l=min(yy[i].x1,yy[j].x1),r=max(yy[i].x1,yy[j].x2);
				for(int k=0;k<cntx;k++)
				{
					if(max(xx[k].y1,xx[k].y2)<=a[2]
					&&min(xx[k].y1,xx[k].y2)>=a[1]
					&&min(xx[k].x1,xx[k].x2)<=l
					&&max(xx[k].x1,xx[k].x2)>=r)
					{
						temp++;
						//printf("xx:%d %d %d %d\n",xx[k].x1,xx[k].y1,xx[k].x2,xx[k].y2);
					} 
				}
				ans+=(temp*temp-temp)/2;
			}
			
		}
	}
	cout<<ans<<endl;
	return 0;
}
