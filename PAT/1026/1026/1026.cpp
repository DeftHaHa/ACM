#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct peo
{
	int arr,t,vip;
	bool serve;
	int tb,te,wait;
}p[10005];
bool cmp(const peo &a,const peo &b)
{
	return a.arr<b.arr;
}
bool cmp2(const peo &a,const peo &b)
{
	return a.serve<b.serve;
}
int main()
{
	int N,tot=0;
	int hh,mm,ss;
	int i;
	cin>>N;
	for(i=0;i<N;i++)
	{
		scanf("%d:%d:%d %d %d",&hh,&mm,&ss,&p[i].t,&p[i].vip);
		p[i].arr=hh*3600+mm*60+ss;
		p[i].serve=false;
	}
	sort(p,p+N,cmp);
	int K,M,t;
	bool vip[105];
	memset(vip,false,sizeof(vip));
	cin>>K>>M;
	while(M--)
	{
		cin>>t;
		vip[t]=true;
	}
	int table[105],tend[105];
	memset(table,0,sizeof(table));
	for(int i=1;i<=K;i++) tend[i]=28800;
	int vipend=28800;
	bool vipturn=false;
	int minend,minvipend,lastvipend=28800;
	for(int i=0;i<N;i++)
	{
		if(p[i].serve) continue;
		minvipend=0x3f3f3f3f;
		for(int j=1;j<=K;j++)
		{
			if(vip[j]) minvipend=min(minvipend,tend[j]);
		}
		int viptag;
		for(int j=1;j<=K;j++) if(tend[j]==minvipend){viptag=j;break;}
		if(minvipend>75600) vipturn=true;
		if(!p[i].serve&&p[i].arr>=lastvipend) vipturn=false;
		bool havevip=false;
		int vipid;
		if(!vipturn)
		{
			for(int j=i;j<N;j++)
			{
				if(!p[i].serve)
				{
					if(p[j].arr>minvipend) break;
					else if(p[j].vip==1)
					{
						havevip=true;
						vipid=i;
						break;
					}
				}
			}
			if(havevip)
			{
				table[viptag]++;
				p[vipid].tb=minvipend;
				p[vipid].te=minvipend+p[vipid].t;
				tend[viptag]=p[vipid].te;
				p[vipid].serve=true;
				p[vipid].wait=minvipend-p[vipid].arr;
				lastvipend=p[vipid].te;
				vipturn=true;
				tot++;
			}
		}
		minend=tend[0];
		int ordtag;
		for(int j=1;j<=K;j++) minend=min(minend,tend[j]);
		if(minend>75600) break; 
		for(int j=1;j<=K;j++) if(tend[j]==minend) {ordtag=j;break;}
		if(!p[i].serve)
		{
			if(minend>p[i].arr)
			{
				p[i].tb=minend;
				p[i].te=minend+p[i].t;
				p[i].wait=minend-p[i].arr;
				
			}
			else
			{
				p[i].tb=p[i].arr;
				p[i].te=p[i].arr+p[i].t;
				p[i].wait=0;
			}
			tend[ordtag]=p[i].te;
			table[ordtag++];
			tot++;
		}	
	}
	sort(p,p+tot,cmp2);
	for(i=0;i<tot;i++)
		printf("%02d:%02d:%02d %02d:%02d:%02d %.0f\n",p[i].arr/3600,p[i].arr%3600/60,p[i].arr%60,p[i].te/3600,p[i].te%3600/60,p[i].te%60,p[i].wait/60.0);
	cout<<table[1];
	for(int i=1;i<=K;i++) cout<<' '<<table[i];
	cout<<endl;
	return 0;
}