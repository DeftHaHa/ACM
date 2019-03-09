#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<map>
using namespace std;
struct SCH{
	int SUM,tot;
	double suma,sumb,sumc;
	string code;
	SCH(){tot = suma = sumb = sumc = 0;}
}sch[200005];
map<string,int> Map;
string low(string s){
	int len = s.length();
	for(int i = 0;i < len;i++){
		if(s[i]>='A'&&s[i]<='Z') s[i] += 32;
	}
	return s;
}
bool cmp(SCH a,SCH b){
	if(a.SUM != b.SUM) return a.SUM > b.SUM;
	if(a.tot != b.tot) return a.tot < b.tot;
	return a.code < b.code;
}
int main()
{
	int N;
	scanf("%d",&N);
	int cnt = 0;
	string s,code;
	double score;
	while(N--){
		cin>>s>>score>>code;
		code = low(code);
		int id = Map[code];
		if(!id){
			Map[code] = ++cnt;
			id = cnt;
			sch[id].code = code;  
		}
		sch[id].tot++;
		if(s[0]=='T') sch[id].suma += score;
		else if(s[0] == 'A') sch[id].sumb += score;
		else sch[id].sumc += score;
	}
	for(int i = 1;i <= cnt;i++){
		sch[i].SUM = (int)(sch[i].suma*1.5 + sch[i].sumb + sch[i].sumc/1.5);
	}
	sort(sch+1,sch+cnt+1,cmp);
	printf("%d\n",cnt);
	int rank = 1,SUM = sch[1].SUM;
	cout<<1<<' '<<sch[1].code<<' '<<sch[1].SUM<<' '<<sch[1].tot<<endl;
	for(int i = 2;i <= cnt;i++){
		if(sch[i].SUM!=sch[i-1].SUM) rank = i;
		cout<<rank<<' '<<sch[i].code<<' '<<sch[i].SUM<<' '<<sch[i].tot<<endl;
	}
	return 0;
}
