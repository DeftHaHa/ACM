#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
char s[105];
bool vis[105];
bool ok = false;
int path[105],ans[105],ac,len;
void dfs(int pos,int cnt){
	if(ok) return;
	if(pos>len){ 
//	cout<<cnt<<"###"<<pos<<endl;
//	for(int i = 1;i < cnt;i++)cout<<path[i]<<' ';
//	cout<<endl;
		bool flag = true;
		for(int i = 1;i < cnt;i++){
			if(!vis[i]){
				flag = false;
				break;
			}
		}
		if(flag){
			for(int i = 1;i < cnt;i++) ans[i] = path[i];
			ac = cnt;
			ok = true;
		}
		return;
	}
	int num = s[pos-1]-'0';
	if(num){
		if(!vis[num]){
			vis[num] = true;
			path[cnt] = num;
			dfs(pos+1,cnt+1);
			vis[num] = false;	
		}
		num = num*10 + s[pos] - '0';
		if(!vis[num] && num < 56&& pos < len){
			vis[num] = true;
			path[cnt] = num;
			dfs(pos+2,cnt+1);
			vis[num] = false;
		}
	}
}
int main()
{
	scanf("%s",s);
	len = strlen(s);
	memset(vis,false,sizeof(vis));
	dfs(1,1);
	printf("%d",ans[1]);
	for(int i = 2;i < ac;i++){
		printf(" %d",ans[i]);
	}
	printf("\n");
	return 0;
}
