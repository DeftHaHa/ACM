#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
struct cmp
{
	bool operator()(int a,int b)
	{
		return a>b;
	}	
};
priority_queue<int,vector<int>,cmp> q;
int main()
{
	int n,k;
	int a;
	cin>>n>>k;
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&a);
		q.push(a);
	}
	int temp = 0;
	while(k--)
	{
		if(q.empty()) printf("0\n");
		else
		{
			while(!q.empty()&&q.top() <= temp) q.pop();
			if(!q.empty())
			{
				printf("%d\n",q.top()-temp);
				temp += q.top()-temp;
			}
			else printf("0\n");
		}
	}
	
	return 0;
}
