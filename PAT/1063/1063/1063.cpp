#include<iostream>
#include<algorithm>
#include<set>
using namespace std;
int main()
{
	int N,M;
	set<int> s[55];
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>M;
		int x;
		while(M--)
		{
			scanf("%d",&x);
			s[i].insert(x);
		}
	}
	int K;
	int a,b;
	cin>>K;
	while(K--)
	{
		scanf("%d%d",&a,&b);
		set<int> temp(s[a].begin(),s[a].end());
		int la=s[a].size(),lb=s[b].size();
		int tot=temp.size()+l;
		
	}
	return 0;
}