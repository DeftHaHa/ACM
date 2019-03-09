#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
#include<algorithm>
using namespace std;
struct peo
{
	string name;
	int id,grade;
}p[100005];
bool cmp1(const peo &a,const peo &b)
{
	return a.id<b.id;
}
bool cmp2(const peo &a,const peo &b)
{
	if(a.name==b.name) return a.id<b.id;
	else return a.name<b.name;
}
bool cmp3(const peo &a,const peo &b)
{
	if(a.grade==b.grade) return a.id<b.id;
	else return a.grade<b.grade;
}
int main()
{
	int N,C;
	while(cin>>N>>C)
	{
		
		for(int i=0;i<N;i++)
		{
			scanf("%d",&p[i].id);
			cin>>p[i].name;
			scanf("%d",&p[i].grade);
		}
		if(C==1) sort(p,p+N,cmp1);
		else if(C==2) sort(p,p+N,cmp2);
		else if(C==3) sort(p,p+N,cmp3);
		for(int i=0;i<N;i++)
		{
			printf("%06d ",p[i].id);
			cout<<p[i].name;
			printf(" %d\n",p[i].grade);
		}
	}
	return 0;
}