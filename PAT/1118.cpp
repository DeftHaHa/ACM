#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int fa[10005],id[10005];
int getfa(int x){
	return fa[x] == x ? x:fa[x] = getfa(fa[x]);
}
int main()
{
	int N,Q,k;
	int a,b;
	scanf("%d",&N);
	memset(fa,0,sizeof(fa));
	for(int i = 1;i <= N;i++){
		scanf("%d",&k);
		for(int i = 0;i < k;i++){
			scanf("%d",&id[i]);
			if(!fa[id[i]]) fa[id[i]] = id[i];
			if(i){
				a = getfa(id[i]);
				b = getfa(id[i-1]);
				if(a != b) fa[a] = b;		
			}
		}
	}
	int tree = 0,bird = 0;
	for(int i = 1;i <= 10000;i++){
		if(fa[i]){
			bird++;
			if(fa[i] == i) tree++;
		}
	}
	printf("%d %d\n",tree,bird);
	scanf("%d",&Q);
	while(Q--){
		scanf("%d%d",&a,&b);
		if(getfa(a)==getfa(b)) puts("Yes");
		else puts("No");
	}
	return 0;
}
