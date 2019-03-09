#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int Rank[10005];
bool is_prime(int n){
	for(int i = 2;i*i <= n;i++){
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int N;
	scanf("%d",&N);
	memset(Rank,0,sizeof(Rank));
	int id;
	for(int i = 1;i <= N;i++){
		scanf("%d",&id);
		Rank[id] = i; 
	}
	scanf("%d",&N);

	while(N--){
		scanf("%d",&id);
		if(!Rank[id]) printf("%04d: Are you kidding?\n",id);
		else if(Rank[id]==-1) printf("%04d: Checked\n",id);
		else if(Rank[id]==1) printf("%04d: Mystery Award\n",id);
		else if(is_prime(Rank[id])) printf("%04d: Minion\n",id);
		else printf("%04d: Chocolate\n",id);
		if(Rank[id]) Rank[id] = -1;
	}
	
	return 0;
}
