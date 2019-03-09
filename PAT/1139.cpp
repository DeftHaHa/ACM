#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int N,M;
const int w = 10000;
vector<int> fs[200005];
int fu[100005],fv[100005],cntu,cntv;
struct ANS{
	int u,v;
};
bool cmp(ANS a,ANS b){
	if(a.u != b.u) return a.u < b.u;
	return a.v < b.v;
}
vector<ANS> ans;
bool judge(int u,int v){
	int len = fs[u].size();
	for(int i = 0;i < len;i++){
		if(fs[u][i] == v) return true;
	}
	return false;
}
int main()
{
	scanf("%d%d",&N,&M);
	int u,v;
	while(M--)
	{
		scanf("%d%d",&u,&v);
		u += w;
		v += w;
		fs[u].push_back(v);
		fs[v].push_back(u);
	}
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		scanf("%d%d",&u,&v);
		u += w;
		v += w;
		int len = fs[u].size();
		cntu = cntv = 0;
		bool sex = u > w;
		for(int i = 0;i < len;i++){
			if( (fs[u][i] < w) ^ sex) {
				fu[cntu++] = fs[u][i];
			}
		}
		len = fs[v].size();
		sex = v > w;
		for(int i = 0;i < len;i++){
			if((fs[v][i] < w) ^ sex){
				fv[cntv++] = fs[v][i];
			}
		}
		vector<ANS> a;
		swap(a,ans);
		for(int i = 0;i < cntu;i++){
			for(int j = 0;j < cntv;j++){
				if(judge(fu[i],fv[j])){
					ans.push_back(ANS{abs(fu[i]-w),abs(fv[j]-w)});
				}
			}
		}
		sort(ans.begin(),ans.end(),cmp);
		int anslen = ans.size();
		printf("%d\n",anslen);
		for(int i = 0;i < anslen;i++){
			printf("%04d %04d\n",ans[i].u,ans[i].v);
		}
	}
	return 0;
}
