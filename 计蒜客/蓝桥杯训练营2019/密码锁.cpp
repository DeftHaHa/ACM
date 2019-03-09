#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<queue>
using namespace std;
bool vis[10005];
int toInt(string s){
	return (s[0] - '0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+s[3]-'0';
}
string ss,se;
struct Node{
	string s;
	int step;
};
queue<Node> q;
int bfs(){
	memset(vis,false,sizeof(vis));
	q.push(Node{ss,0});
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 3;j++){
				string ts = now.s;
				if(j==0){
					if(ts[i]=='9') ts[i] = '1';
					else ts[i] += 1;
				}
				else if(j==1){
					if(ts[i]=='1') ts[i] = '9';
					else ts[i]-=1;
				}
				else{
					if(i<3) swap(ts[i],ts[i+1]);
				}
				
				int next = toInt(ts);
				if(!vis[next]){
					if(ts == se) return now.step + 1;
					vis[next] = true;
					q.push(Node{ts,now.step+1});
				}
			}
		}
	}
} 
int main()
{
	cin>>ss>>se;
	cout<<bfs()<<endl;
	return 0;
}
