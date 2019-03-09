#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct PEO{
	char s[10];
	int h;
};
bool cmp(PEO a,PEO b){
	if(a.h != b.h) return a.h > b.h;
	return strcmp(a.s,b.s)<0;
}
vector<int> ans[15];
vector<PEO> peo;
int main()
{
	int N,K;
	scanf("%d%d",&N,&K);
	peo = vector<PEO>(N+1);
	for(int i = 1;i <= N;i++){
		scanf("%s%d",peo[i].s,&peo[i].h);
	}
	sort(peo.begin()+1,peo.begin()+N+1,cmp);
	int len = N/K,S = 0;
	for(int row = 1;row <= K;row++){
		int cnt = (row == 1 ? len+N%K : len);
		int mid = cnt/2+1;
		ans[row] = vector<int>(cnt);
		int l = mid-1,r = mid+1,tot = 1;
		bool L = true;
		ans[row][mid] = S+1;
		for(int i = S+2;i<=N;i++){
			if(L) ans[row][l--] = i;
			else ans[row][r++] = i;
			L = !L;
			tot++;
			if(tot == cnt) break;
		//	if(l<1||r>cnt) continue;
		}
		S += cnt;
	}
	for(int row = 1;row <= K;row++){
		int cnt = (row == 1 ? len+N%K : len);
		printf("%s",peo[ans[row][1]].s);
		for(int i = 2;i <= cnt;i++) printf(" %s",peo[ans[row][i]].s);
		puts("");
	}
	
	return 0;
}
