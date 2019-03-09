#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct Info{
	int id,fa,ma,k,ch[6],M,A;
}info[1005];
struct Family{
	int minId,M,As,Aa;
	double avs,ava;
	Family(){minId = 0x3f3f3f3f; M = As = Aa = 0;}
}f[10005],ans[10005];
int fa[10005],vis[10005];
int getfa(int x){
	return fa[x] == x ? x : fa[x] = getfa(fa[x]);
}
void merge(int a,int b){
	a = getfa(a);
	b = getfa(b);
	if(a!=b) fa[b] = a;
}
bool cmp(Family a,Family b){
	if(a.ava != b.ava) return a.ava > b.ava;
	return a.minId < b.minId;
}
int main()
{
	for(int i = 1;i <= 10000;i++) fa[i] = i;
	int N;
	scanf("%d",&N);
	for(int i = 1;i <= N ;i++){
		scanf("%d%d%d%d",&info[i].id,&info[i].fa,&info[i].ma,&info[i].k);
 		if(info[i].fa != -1) merge(info[i].id,info[i].fa);
 		if(info[i].ma != -1) merge(info[i].id,info[i].ma);
		for(int j = 0;j < info[i].k;j++){
			scanf("%d",&info[i].ch[j]);
			merge(info[i].id,info[i].ch[j]);
		}
		scanf("%d%d",&info[i].M,&info[i].A);
	}
	memset(vis,false,sizeof(vis));
	for(int i = 1;i <= N;i++){
		int FA = getfa(info[i].id);
		f[FA].minId = min(info[i].id,f[FA].minId);
		if(!vis[info[i].id]) f[FA].M += 1,vis[info[i].id] = true;
		if(info[i].fa != -1 && !vis[info[i].fa]) f[FA].M += 1,f[FA].minId=min(f[FA].minId,info[i].fa),vis[info[i].fa] = true;
		if(info[i].ma != -1 && !vis[info[i].ma]) f[FA].M += 1,f[FA].minId=min(f[FA].minId,info[i].ma),vis[info[i].ma] = true;
		for(int j = 0;j < info[i].k;j++){
			if(!vis[info[i].ch[j]]){
				vis[info[i].ch[j]] = true;
				f[FA].M++;
				f[FA].minId = min(f[FA].minId,info[i].ch[j]);
			}
		}
		f[FA].As += info[i].M;
		f[FA].Aa += info[i].A;
	}
	int cnt = 0;
	for(int i = 0;i <= 10000;i++){
		if(f[i].M){
			ans[cnt++] = f[i];
			ans[cnt-1].avs = (double)f[i].As/(double)f[i].M;
			ans[cnt-1].ava = (double)f[i].Aa/(double)f[i].M;
		}
	}
	sort(ans,ans+cnt,cmp);
	printf("%d\n",cnt);
	for(int i = 0;i < cnt;i++){
		printf("%04d %d %.3lf %.3lf\n",ans[i].minId,ans[i].M,ans[i].avs,ans[i].ava);
	}
	return 0;
}
