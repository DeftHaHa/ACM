#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;
int N,len;
map<string,bool> vis,vis2;
struct Node{
	string s;
	int pos;
};
queue<Node> q;
int cnt = 0;
void bfs(string s)
{
	q.push(Node{s,N});
	vis[s] = true;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		string ss = now.s; 
		string com = ss.substr(0,now.pos) + ss.substr(now.pos+1,len-now.pos-1);
		if(!vis2[com]){
			vis2[com] = true;
			cnt++;
			printf("%d",now.pos+1);
		//	cout<<com<<endl;
			if(cnt%5==0) printf("\n");
			else printf(" ");
		}
		if(now.pos > 0){
			swap(ss[now.pos-1],ss[now.pos]);
			if(!vis[ss]) vis[ss] = true,q.push(Node{ss,now.pos-1});
		}
		ss = now.s;
		if(now.pos < len-1){
			swap(ss[now.pos+1],ss[now.pos]);
			if(!vis[ss]) vis[ss] = true,q.push(Node{ss,now.pos+1});
		}
		ss = now.s;
		if(now.pos > 1 && ss[now.pos-2] != ss[now.pos-1]){
			swap(ss[now.pos-2],ss[now.pos]);
			if(!vis[ss]) vis[ss] = true,q.push(Node{ss,now.pos-2});
		}
		ss = now.s;
		if(now.pos < len-2 && ss[now.pos+2] != ss[now.pos+1]){
			swap(ss[now.pos+2],ss[now.pos]);
			if(!vis[ss]) vis[ss] = true,q.push(Node{ss,now.pos+2});
		}
	}
}
int main()
{
	scanf("%d",&N);
	len = N*2+1;
	string s = "";
	for(int i = 0;i < N;i++) s+='W';
	s+='#';
	for(int i = 0;i < N;i++) s+='B';
	bfs(s);
	printf("\n");
	return 0;
}
