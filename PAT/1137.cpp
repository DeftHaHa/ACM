#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<cmath>
#include<algorithm>
using namespace std;
struct STU{
	string s;
	int gp,gm,gf,G;
	STU(){gp = gm = gf = -1;}
}stu[100005];
map<string,int> Map;
bool cmp(STU a,STU b){
	if(a.G!=b.G) return a.G > b.G;
	return a.s < b.s;
}
int main()
{
	int P,M,N;
	scanf("%d%d%d",&P,&M,&N);
	string s;
	int score;
	int cnt = 0;
	while(P--){
		cin>>s;
		scanf("%d",&score);
		int index = Map[s];
		if(!index){
			Map[s] = ++cnt;
			index = cnt;
			stu[index].s = s;
		}
		stu[index].gp = score;
	}
	while(M--){
		cin>>s;
		scanf("%d",&score);
		int index = Map[s];
		if(!index){
			Map[s] = ++cnt;
			index = cnt;
			stu[index].s = s;
		}
		stu[index].gm = score;
	}
	while(N--){
		cin>>s;
		scanf("%d",&score);
		int index = Map[s];
		if(!index){
			Map[s] = ++cnt;
			index = cnt;
			stu[index].s = s;
		}
		stu[index].gf = score;
	}
	for(int i = 1; i <= cnt;i++){
		if(stu[i].gm > stu[i].gf){
			stu[i].G = round(0.4*stu[i].gm + 0.6*stu[i].gf);	
		}
		else stu[i].G = stu[i].gf;
	}
	sort(stu+1,stu+cnt+1,cmp);
	for(int i = 1; i <= cnt;i++){
		if(stu[i].gp < 200 || stu[i].G < 60) continue;
		cout<<stu[i].s;
		printf(" %d %d %d %d\n",stu[i].gp,stu[i].gm,stu[i].gf,stu[i].G);
	}
	return 0;
}
