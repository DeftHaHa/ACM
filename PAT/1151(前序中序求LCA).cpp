#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
int ino[20005],pre[20005];
int M,N,u,v;
int upos,vpos;
map<int,int> Map;
void LCA(int pos,int l,int r){
//	cout<<"->"<<pre[pos]<<' '<<l<<' '<<r<<endl;
	if(l>r) return;
	int tag = Map[pre[pos]];
	if(upos < tag && vpos > tag|| upos > tag && vpos < tag) printf("LCA of %d and %d is %d.\n",u,v,pre[pos]);//!!!两边有两种情况
	else if((upos < tag && vpos < tag )) LCA(pos+1,l,tag-1);
	else if(upos > tag && vpos > tag) LCA(pos+tag-l+1,tag+1,r);
	else if(upos == tag) printf("%d is an ancestor of %d.\n",u,v);
	else if(vpos == tag) printf("%d is an ancestor of %d.\n",v,u);
}
int main()
{
	scanf("%d%d",&M,&N);
	for(int i = 1;i <= N;i++){
		scanf("%d",&ino[i]);
		Map[ino[i]]=i;
	}
	for(int i = 1;i <= N;i++) scanf("%d",&pre[i]);
	while(M--){
		scanf("%d%d",&u,&v);
		int flag1 = Map[u],flag2 = Map[v];
		if(!flag1&&!flag2) printf("ERROR: %d and %d are not found.\n",u,v);
		else if(!flag1) printf("ERROR: %d is not found.\n",u);
		else if(!flag2) printf("ERROR: %d is not found.\n",v);
		else {
			upos = Map[u];
			vpos = Map[v];
			LCA(1,1,N);	
		}
	}
	return 0;
}
