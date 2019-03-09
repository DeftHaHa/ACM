#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map> 
using namespace std;
int ans[105],t[50005];
bool inq[50005];
bool cmp(int a,int b){
	if(t[a]!=t[b]) return t[a]>t[b];
	return a<b;
}
int main()
{
	memset(t,0,sizeof(t));
	memset(inq,false,sizeof(inq));
	int N,K;
	scanf("%d%d",&N,&K);
	int a,cnt = 0;
	scanf("%d",&a);
	N--;
	while(N--){
		t[a]++;
		if(!inq[a]){
			if(cnt < K) ans[++cnt] = a,inq[a] = true;
			else if(t[a]>t[ans[K]] || (t[a]==t[ans[K]] && a<ans[K])){
				ans[K] = a,inq[a] = true,inq[ans[K]] = false;	
			}
		}
		sort(ans+1,ans+cnt+1,cmp);
		scanf("%d",&a);
		printf("%d:",a);
		for(int i = 1;i <= cnt;i++) printf(" %d",ans[i]);
		puts("");
	}
	return 0;
}

