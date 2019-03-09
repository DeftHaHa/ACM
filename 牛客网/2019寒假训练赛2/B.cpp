#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
#include<iostream>
using namespace std;
map<string,int> Map; 
char s[25];
int Score[6] = {0,500,1000,1500,2000,2500};
struct PEO{
	int score[6],wa[6];
	int sum,flag;
	PEO(){
		for(int i = 1;i <= 5;i++) score[i] = wa[i] = 0;
		sum = flag = 0;
	}
}peo[505];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n;i++){
		scanf("%s",s);
		Map[s] = i;
	}
	int T;
	char S[25],P,V[5];
	while(m--){
		scanf("%d %s %c %s",&T,S,&P,V);
		int id = Map[S],pid = P - 'A' + 1;
		if(V[0]=='A'){
			peo[id].score[pid] = max((int)(0.3*Score[pid]),Score[pid]-Score[pid]/250*T-50*peo[id].wa[pid]);
			peo[id].wa[pid]++;
		}
		else if(V[0] == 'W' || V[0] == 'T'){
			peo[id].wa[pid]++;
			peo[id].score[pid] = 0;
		}
		else peo[id].score[pid] = 0;
		peo[id].flag = 1;
	}
	int TOT = 0;
	for(int i = 1;i <=n ;i++){
		peo[i].sum = 0;
		if(peo[i].flag) TOT++;
		for(int j = 1;j <= 5;j++) peo[i].sum += peo[i].score[j];
	}
	if(!Map["cnz"] || !peo[Map["cnz"]].flag) puts("-1");
	else{
		int rank = 1,id = Map["cnz"];
		for(int i = 1;i <= n;i++){
			//cout<<i<<' '<<peo[i].sum<<endl;
			if(peo[i].sum > peo[id].sum) rank++;
		}
		printf("%d\n%d/%d\n",peo[id].sum,rank,TOT);
	}
	return 0;
}

