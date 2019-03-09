#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
struct school
{
	string name;
	int score;
	int cnt;
}sch[1000005];
bool cmp(const school &a,const school &b)
{
	if(a.score==b.score)
	{
		if(a.cnt==b.cnt) return a.name<b.name;
		else return a.cnt<b.cnt;
	}
	else return a.score>b.score;
}
int main()
{
	int N;
	cin>>N;
	int tot=0;
	map<string,int> Map;
	string id,sname;
	double sc;
	for(int i=0;i<N;i++)
	{
		cin>>id>>sc>>sname;
		for(int i=0;i<sname.length();i++) if(sname[i]>='A'&&sname[i]<='Z') sname[i]+=32;
		int tag=0;
		if(Map.count(sname)) tag=Map[sname];
		else
		{
			Map[sname]=tot++;
			tag=tot-1;
			sch[tag].name=sname;
			sch[tag].cnt=0;
			sch[tag].score=0;
		}
		sch[tag].cnt++;
		if(id[0]=='B') sch[tag].score+=(int)(sc/1.5);
		else if(id[0]=='A') sch[tag].score+=(int)(sc);
		else sch[tag].score+=(int)(sc*1.5);
	}
	sort(sch,sch+tot,cmp);
	cout<<tot-1<<endl;
	int order=1;
	for(int i=0;i<tot;i++)
	{
		if(i>0&&sch[i].score!=sch[i-1].score) order=i+1;
		cout<<order<<' '<<sch[i].name<<' '<<sch[i].score<<' '<<sch[i].cnt<<endl;
	}
	system("pause");

	return 0;
}