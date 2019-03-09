#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int cnt = 0;
struct NUM{
	int n,tot;
	NUM(){tot = 0;}
}num[100005];
map<int,int> Map;
int main(){
	int n,x;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&x);
		int id = Map[x];
		if(!id){
			Map[x] = ++cnt;
			id = cnt;
			num[id].n = x;
		}
		num[id].tot++;
	}
	int Mcnt = 0,Anum;
	for(int i = 1; i<= cnt;i++){
		if(num[i].tot > Mcnt){
			Mcnt = num[i].tot;
			Anum = num[i].n;
		}
		else if(num[i].tot == Mcnt && num[i].n > Anum) Anum = num[i].n;
	}
	printf("%d %d\n",Anum,Mcnt);
	return 0;
}
