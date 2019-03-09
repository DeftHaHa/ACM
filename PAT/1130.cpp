#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
struct Node{
	string data;
	int l,r;
}node[25];
bool is_root[25];
int root;
void dfs(int pos){
	if(node[pos].l ==-1 && node[pos].r ==-1) return;
	if(node[pos].l !=-1 ) dfs(node[pos].l);
	if(node[pos].r !=-1 ) dfs(node[pos].r);
	string t;
	if(pos!=root) t += "(";
	if(node[pos].l !=-1 ) t += node[node[pos].l].data;
	t += node[pos].data;
	if(node[pos].r !=-1 ) t += node[node[pos].r].data;
	if(pos!=root) t += ")";
	node[pos].data = t;
}
int main(){
	int N;
	scanf("%d",&N);
	memset(is_root,true,sizeof(is_root));
	for(int i = 1;i <= N;i++){
		cin>>node[i].data >> node[i].l >>node[i].r;
		if(node[i].l != -1) is_root[node[i].l] = false;
		if(node[i].r != -1) is_root[node[i].r] = false;
	}
	for(int i = 1;i <= N;i++) if(is_root[i]) root = i;
	dfs(root);
	int len = node[root].data.length();
	cout<<node[root].data<<endl;
	//for(int i = 1;i < len-1;i++) printf("%c",node[root].data[i]);
	//puts("");
	return 0;
}
