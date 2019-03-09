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
	int a[50005],cnt = 0;
	scanf("%d",&a[1]);
	for(int i = 2;i <= N;i++){
		scanf("%d",&a[i]);
		t[a[i-1]]++; 
		if(!inq[a[i-1]]){
			if(cnt < K) ans[++cnt] = a[i-1],inq[a[i-1]] = true;
			else if(t[a[i-1]]>t[ans[K]] || (t[a[i-1]]==t[ans[K]] && a[i-1]<ans[K])){
				inq[ans[K]] = false,ans[K] = a[i-1],inq[a[i-1]] = true;
				//if(i==8) printf("inq[3] = %d  t[3] = %d  ans[k]=%d:%d\n",inq[3],t[3],ans[K],t[ans[K]]);
			}
		}
		sort(ans+1,ans+cnt+1,cmp);
		printf("%d:",a[i]);
		for(int j = 1;j <= cnt;j++) printf(" %d",ans[j]);
		puts("");
	}
	return 0;
}
/*
9 2
9 3 7 6 4 1 4 3 9
*/
