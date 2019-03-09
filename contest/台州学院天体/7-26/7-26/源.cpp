#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N;
	int s[1005],e[1005];
	while(cin>>N)
	{
		int day=0,id,h,m;
		char ch;
		memset(s,0,sizeof(s));
		memset(e,0,sizeof(e));
		int tot=0,T=0;
		while(day<N)
		{
			scanf("%d %c %d:%d",&id,&ch,&h,&m);
			if(id==0)
			{
				
				if(tot)
				{
					double ans=(double)T/(double)tot;
					if(ans-(int)ans>0) ans+=1;
					printf("%d %d\n",tot,(int)ans);
				}
				else printf("0 0\n");
				day++;
				tot=0;
				T=0;
				memset(s,0,sizeof(s));
				memset(e,0,sizeof(e));
			}
			else
			{
				if(ch=='S')
				{
					s[id]=h*60+m;
					if(e[id])
					{
						tot++;
						T+=e[id]-s[id];
					}
				}
				else if(ch=='E')
				{
					e[id]=h*60+m;
					if(s[id])
					{
						tot++;
						T+=e[id]-s[id];
					}
				}
			}
			
		}
	}
	return 0;
}