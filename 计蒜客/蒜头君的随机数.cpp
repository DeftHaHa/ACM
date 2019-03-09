#include<iostream>
#include<cstdio>
#include<set>
using namespace std;
int main()
{
	int N,n;
	cin>>N;
	set<int> s;
	while(N--)
	{
		scanf("%d",&n);
		s.insert(n);
	}
	printf("%d\n",s.size());
	set<int>::iterator it=s.begin();
	printf("%d",*it);
	it++;
	for(;it!=s.end();it++)
	{
		printf(" %d",*it);
	}
	printf("\n");
	return 0;
}
