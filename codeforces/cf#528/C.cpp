#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
struct Node
{
	int x,y;	
}node[3],ans[1000005];
bool cmp1(Node a,Node b){
	return a.x < b.x;
}
bool cmp2(Node a,Node b){
	return a.y < b.y;
}
bool cl[1005][1005];
int main()
{
	int cnt = 0;	
	memset(cl,false,sizeof(cl));
	for(int i = 0 ; i < 3;i++){
		scanf("%d%d",&node[i].x,&node[i].y);
		cl[node[i].x][node[i].y] = true;
		ans[cnt].x = node[i].x;
		ans[cnt++].y = node[i].y;
	}
	sort(node,node+3,cmp1);
	sort(node,node+3,cmp2);
	if(node[1].y < node[2].y){
		for(int j = node[2].y;j>=node[1].y;j--) 
			if(!cl[node[2].x][j])
			{
				cl[node[2].x][j] = true;
				ans[cnt].x = node[2].x;
				ans[cnt++].y = j;
			}
	}
	else
	{
		for(int j = node[2].y;j<=node[1].y;j++) 
			if(!cl[node[2].x][j])
			{
				cl[node[2].x][j] = true;
				ans[cnt].x = node[2].x;
				ans[cnt++].y = j;
			}
	}
		
	for(int i = node[2].x;i >= node[1].x;i--)
	{
		if(!cl[i][node[1].y])
		{
			cl[i][node[1].y] = true;
			ans[cnt].x = i;
			ans[cnt++].y = node[1].y;
		}
	}
	if(node[0].y < node[1].y){
		for(int j = node[1].y;j>=node[0].y;j--) 
			if(!cl[node[1].x][j])
			{
				cl[node[1].x][j] = true;
				ans[cnt].x = node[1].x;
				ans[cnt++].y = j;
			}
	}
	else{
		for(int j = node[1].y;j<=node[0].y;j++) 
			if(!cl[node[1].x][j])
			{
				cl[node[1].x][j] = true;
				ans[cnt].x = node[1].x;
				ans[cnt++].y = j;
			}
	}
	for(int i = node[1].x;i >= node[0].x;i--)
	{
		if(!cl[i][node[0].y])
		{
			cl[i][node[0].y] = true;
			ans[cnt].x = i;
			ans[cnt++].y = node[0].y;
		}
	}
	cout<<cnt<<endl;
	for(int i = 0 ; i < cnt;i++){
		printf("%d %d\n",ans[i].x,ans[i].y);
	}
	return 0;
}
