#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
int ans=0x3f3f3f3f;
void dfs(vector<int> now,int sum)
{
	if(now.size()==1)
	{
		ans=min(ans,sum);
		return;
	}
	if(sum>=ans) return;
	for(int i=0;i<now.size()-1;i++)
	{
		vector<int> next=now;
		next[i]+=next[i+1];
		next.erase(next.begin()+i+1);
		dfs(next,sum+next[i]);
	}
}
int main()
{
	int a[11]={13,1,45,7,20,4,19,13,40,33,38};
	vector<int> x;
	for(int i=0;i<11;i++) x.push_back(a[i]);
	dfs(x,0);
	cout<<ans<<endl;
	return 0;
}
