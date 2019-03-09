#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int n;
int len[25];
bool vis[25];
int sum = 0,aim;
int flag = 0;
void dfs(int pos,int sum){
	if(sum == aim ||(flag && sum == aim*2)) flag++;
	if(flag == 2) return;
	for(int i = pos+1;i <= n;i++){
		if(!vis[i]) 
		{
			vis[i] = true;
			dfs(i,sum+len[i]);
			vis[i] = false;
		}
	}
}
int main()
{
//	freopen("triangle.in","r",stdin);
//	freopen("triangle.out","w",stdout);
	
	cin>>n;
	for(int i = 1;i <= n;i++){
		scanf("%d",&len[i]);
		sum += len[i];
	}
	if(sum%3){
		cout<<"no"<<endl;
		return 0;
	}
	aim = sum / 3;
	dfs(0,0);
	if(flag >= 2) cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	return 0;
}
