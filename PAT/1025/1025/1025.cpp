#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
struct peo
{
	string id;
	int grade,frank,location,lrank;
}p[30005];
bool cmp(const peo &a,const peo &b)
{
	if(a.grade==b.grade) return a.id<b.id;
	else return a.grade>b.grade;
}
int main()
{
	int N,M;
	cin>>N;
	int totend=0,tot,rank,temp;
	for(int i=1;i<=N;i++)
	{
		cin>>M;
		for(int j=totend;j<totend+M;j++)
		{
			cin>>p[j].id>>p[j].grade;
			p[j].location=i;
		}
		sort(p+totend,p+totend+M,cmp);
		tot=1;
		rank=1;
		temp=p[totend].grade;
		for(int j=totend;j<totend+M;j++)
		{
			if(p[j].grade!=temp) rank=tot;
			p[j].lrank=rank;
			tot++;
			temp=p[j].grade;
		}
		totend+=M;
	}
	sort(p,p+totend,cmp);
	cout<<totend<<endl;
	tot=1;
	rank=1;
	temp=p[0].grade;
	for(int j=0;j<totend;j++)
	{
		if(p[j].grade!=temp) rank=tot;
		p[j].frank=rank;
		tot++;
		temp=p[j].grade;
		cout<<p[j].id;
		printf(" %d %d %d\n",p[j].frank,p[j].location,p[j].lrank);
	}
	return 0;
}