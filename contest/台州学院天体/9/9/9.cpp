#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
	set<int> s[55];
	int N,M;
	while(cin>>N)
	{
		for(int i=1;i<=N;i++)
		{
			int n;
			scanf("%d",&M);
			while(M--)
			{
				scanf("%d",&n);
				s[i].insert(n);
			}
		}
		int K,qa,qb;
		cin>>K;
		while(K--)
		{
			scanf("%d%d",&qa,&qb);
			set<int>::iterator it;
			int la=s[qa].size(),lb=s[qb].size();
			int com=0;
			for(it=s[qa].begin();it!=s[qa].end();it++)
			{
				if(s[qb].count(*it)) com++;
			}
			double ans=(double)com/(double)(la+lb-com);
			printf("%.2lf%%\n",ans*100);
		}
	}
	return 0;
}