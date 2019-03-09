#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int N,M;
vector<int> e[205];
int main(){
	scanf("%d%d",&N,&M);
	int u,v;
	while(M--){
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	int K;
	int node[205];
	bool vis[205];
	vector<int> el;
	int Q;
	scanf("%d",&Q);
	while(Q--){
		scanf("%d",&K);
		memset(vis,false,sizeof(vis));
		bool flag = true;
		for(int i = 0;i < K;i++){
			scanf("%d",&node[i]);
			vis[node[i]] = true;
		}
		vector<int> x;
		swap(x,el);
		for(int i = 0;i < K;i++){
			int cnt = 0,len = e[node[i]].size();
			for(int j = 0;j < len;j++){
				if(vis[e[node[i]][j]]) cnt++;
				else el.push_back(e[node[i]][j]);
			}
			if(cnt != K-1){
				flag = false;
				break;
			}
		}
		bool notMax = false; 
		if(flag){
			int l = el.size();
			for(int x = 0;x < l;x++){
				bool temp = true;
				node[K] = el[x];
				vis[el[x]] = true;
				for(int i = 0;i <= K;i++){
					int cnt = 0,len = e[node[i]].size();
					for(int j = 0;j < len;j++){
						if(vis[e[node[i]][j]]) cnt++;
					}
					if(cnt != K){
						temp = false;
						break;
					}
				}
				vis[el[x]] = false;
				if(temp){
					notMax = true;
					break;
				}
			}
		}
		if(flag){
			if(notMax) printf("Not Maximal\n");
			else printf("Yes\n");
		}
		else printf("Not a Clique\n");
	}
	return 0;
}
