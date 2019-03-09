#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct peo
{
	char name[9];
	int w,age;
}p[100005];
bool cmp(const peo &a,const peo &b)
{
		if(a.w==b.w)
		{
			if(a.age==b.age) return strcmp(a.name,b.name)<0;
			else return a.age<b.age;
		}
		else return a.w>b.w;
}
int main()
{
	int N,K;
	cin>>N>>K;
	for(int i=0;i<N;i++) scanf("%s%d%d",p[i].name,&p[i].age,&p[i].w);
	int M,b,e,tot=0,c=0;
	sort(p,p+N,cmp);
	while(K--)
	{
		scanf("%d%d%d",&M,&b,&e);
		printf("Case #%d:\n",++c);
		tot=0;
		for(int i=0;i<N;i++)
		{
			if(p[i].age>=b&&p[i].age<=e)
			{
				printf("%s %d %d\n",p[i].name,p[i].age,p[i].w);
				tot++;
				if(tot==M) break;
			}
		}
		if(tot==0) printf("None\n");
	}
	return 0;
}