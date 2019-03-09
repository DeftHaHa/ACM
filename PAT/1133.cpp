#include<iostream>
#include<cstdio>
#include<malloc.h>
#include<cstring>
#include<cmath>
#include<map>
#include<algorithm>
using namespace std;
struct Node{
	int ad,v,next;
}node[1000005],num[1000005];
int k;
int main()
{
	int sid,v,n,a,b;
	scanf("%d%d%d",&sid,&n,&k);
	for(int i = 0;i < n;i++){
		scanf("%d%d%d",&a,&v,&b);
		node[a].ad = a;
		node[a].v = v;
		node[a].next = b;
	} 
	int now = sid,cnt = 0;
	while(now!=-1){
		if(node[now].v < 0){
			num[cnt++] = node[now];	
		}
		now = node[now].next;
	}
	now = sid;
	while(now!=-1){
		if(node[now].v >=0 && node[now].v <= k) num[cnt++] = node[now];
		now = node[now].next;
	}
	now = sid;
	while(now!=-1){
		if(node[now].v > k) num[cnt++] = node[now];
		now = node[now].next;
	}//puts("+======+");
	for(int i = 0;i < cnt-1;i++){
		printf("%05d %d %05d\n",num[i].ad,num[i].v,num[i+1].ad);
	}
	printf("%05d %d -1\n",num[cnt-1].ad,num[cnt-1].v);
	return 0;
}
