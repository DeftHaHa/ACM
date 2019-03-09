#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
int n,A,B;
struct Node{
	int x,step;
};
queue<Node> q;
bool vis[5005];
int bfs(){
	memset(vis,false,sizeof(vis));
	q.push(Node{A,0});
	vis[A] = true;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		//cout<<now.x<<endl;
		int tx = now.x + 1;
		if(tx > 0 && tx <= n &&! vis[tx]){
			if(tx == B) return now.step + 1;
			vis[tx] = true;
			q.push(Node{tx,now.step+1});
		}
		tx = now.x - 1; 
		if(tx > 0 && tx <= n && !vis[tx]){
			if(tx == B) return now.step + 1;
			vis[tx] = true;
			q.push(Node{tx,now.step+1});
		}
		tx = now.x * 2;
		if(tx > 0 && tx <= n && !vis[tx]){
			if(tx == B) return now.step + 1;
			vis[tx] = true;
			q.push(Node{tx,now.step+1});
		}
	}
}
int main()
{
	cin>>n>>A>>B;
	cout<<bfs()<<endl;
	return 0;
}
