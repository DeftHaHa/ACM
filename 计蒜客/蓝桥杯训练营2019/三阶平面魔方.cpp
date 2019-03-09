#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<queue>
using namespace std;
struct Node{
	string s;
	int step;
};
map<string,bool> vis;
string en = "123456789";
string cr(string s,int r,bool f){
	int l = r*3;
	if(f){
		swap(s[l],s[l+1]);
		swap(s[l+1],s[l+2]);
	}
	else{
		swap(s[l+1],s[l+2]);
		swap(s[l],s[l+1]);
	}
	return s;
}
string cc(string s,int c,bool f){
	if(f){
		swap(s[c],s[c+3]);
		swap(s[c+3],s[c+6]);
	}
	else{
		swap(s[c+3],s[c+6]);
		swap(s[c],s[c+3]);
	}
	return s;
}
queue<Node> q;
int bfs(string ss){
	q.push(Node{ss,0});
	vis[ss] = true;
	while(!q.empty()){
		Node now = q.front();
		q.pop();
		for(int i = 0;i < 6;i++){
			for(int j = 0;j < 2;j++){
				string ns;
				if(i<3) ns = cr(now.s,i,j);
				else ns = cc(now.s,i-3,j);
				if(ns == en) return now.step+1;
				if(!vis[ns]){
					vis[ns] = true;
					q.push(Node{ns,now.step+1});
				}	
			}
		} 
	}
	return -1;
} 
int main()
{
	string s;
	string t;
	int x = 3;
	while(x--){
		cin>>t;
		s+=t;
	}
	cout<<bfs(s)<<endl;
	
	return 0;
}
