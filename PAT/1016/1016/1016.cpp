#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct data
{
	string name;
	int mo,dd,hh,mm;
	bool start;
}p[1005];
bool cmp(const data &a,const data &b)
{
	if(a.name==b.name)
	{
		if(a.mo==b.mo)
		{
			if(a.hh==b.hh) return a.mm<b.mm;
			else return a.hh<b.hh;
		}
		else return a.mo<b.mo;
	}
	else return a.name<b.name;
}
int main()
{
	int toll[25];
	int N;
	while(cin>>toll[0])
	{
		for(int i=1;i<24;i++) cin>>toll[i];
		cin>>N;
		string s1,s2;
		for(int i=0;i<N;i++)
		{
			cin>>p[i].name;
			scanf("%d:%d:%d:%d",&p[i].mo,&p[i].dd,&p[i].hh,&p[i].mm);
			cin>>s2;
			if(s2[1]=='n') p[i].start=true;
			else p[i].start=false;
		}                     
		sort(p,p+N,cmp);
		string name=p[0].name;
		bool start=p[0].start;
		int ts[1005]={0},te[1005]={0},tot=0;
		int mo=p[0].mo;
		for(int i=1;i<N;i++)
		{ 
			if(p[i].name==name)
			{
				if(mo==p[i].mo)
				{
					if(start&&!p[i].start)
					{
						if(!p[i].start)
						{
							te[tot++]=i;
							start=false;
						}
						else ts[tot]=i;	
					}
					else start=p[i].start;
				}
				else
				{
					if(tot>0)
					{
						cout<<name<<' '<<mo<<endl;
						for(int j=0;j<tot;j++)
						{
							int tag=ts[j];
							int sum=0;
							int tstart=p[tag].dd*24*60+p[tag].hh*60+p[tag].mm;
							printf("%02d:%02d:%02d",p[tag].dd,p[tag].hh,p[tag].mm);
							tag=te[j];
							int tend=p[tag].dd*24*60+p[tag].hh*60+p[tag].mm;
							if(p[ts[j]].hh==p[te[j]].hh)
								sum=(p[te[j]].mm-p[ts[j]].mm)*toll[p[ts[j]].hh];
							else
							{
								sum+=60-p[ts[j]].mm*toll[p[ts[j]].hh];
								sum+=p[te[j]].mm*toll[p[te[j]].hh];
								for(int k=p[ts[j]].hh+1;k<=p[te[j]].hh-1;j++)
									sum+=60*toll[k];
							}
							printf(" %02d:%02d:%02d %d $%.2f\n",p[tag].dd,p[tag].hh,p[tag].mm,tend-tstart,float(sum)/100);
						}
					}
					start=false;
					tot=0;
					mo=p[i].mo;
				}
			}
			else
			{
				if(tot>0)
					{
						cout<<name<<' '<<mo<<endl;
						for(int j=0;j<tot;j++)
						{
							int tag=ts[j];
							int sum=0;
							int tstart=p[tag].dd*24*60+p[tag].hh*60+p[tag].mm;
							printf("%02d:%02d:%02d",p[tag].dd,p[tag].hh,p[tag].mm);
							tag=te[j];
							int tend=p[tag].dd*24*60+p[tag].hh*60+p[tag].mm;
							if(p[ts[j]].hh==p[te[j]].hh)
								sum=(p[te[j]].mm-p[ts[j]].mm)*toll[p[ts[j]].hh];
							else
							{
								sum+=60-p[ts[j]].mm*toll[p[ts[j]].hh];
								sum+=p[te[j]].mm*toll[p[te[j]].hh];
								for(int k=p[ts[j]].hh+1;k<=p[te[j]].hh-1;j++)
									sum+=60*toll[k];
							}
							printf(" %02d:%02d:%02d %d $%.2f\n",p[tag].dd,p[tag].hh,p[tag].mm,tend-tstart,float(sum)/100);
						}
				}
				name=p[i].name;
				tot=0;
				mo=p[i].mo;
				start=false;
			}
		}
	}
	return 0;
}