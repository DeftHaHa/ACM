#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
#include<map>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
int rot[30];
set<vector<int> > Set;
vector<int> a;
void rotate(){
	vector<int> tmp;
	for(int i = 0;i < 5;i++){
		tmp.push_back(rot[a[i]]);
	}
	sort(tmp.begin(),tmp.end());
	a = tmp;
}
void dfs(int n){
	if(a.size() == 5){
		vector<int> now = a;
		for(int i = 0;i < 4;i++){
			rotate();
			now = min(now,a);
		}
		Set.insert(now);
		return;
	}
	if(n == 26) return;
	a.push_back(n);
	dfs(n+1);
	a.pop_back();
	dfs(n+1);
}
int main()
{

	int t = 0;
	for(int j = 5;j >= 1;j--){
		for(int i  = 1;i <= 5;i++){
			rot[++t] = (i-1)*5+j;
		}
	}
	dfs(1);
	cout<<Set.size()<<endl;
	return 0;
}
