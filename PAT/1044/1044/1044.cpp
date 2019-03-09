#include<cstdio>
#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
int main()
{
	int N,M;
	int d[100005];
	cin>>N>>M;
	for(int i=1;i<=N;i++) scanf("%d",&d[i]);
	int i,j,minm=0x3f3f3f3f,sum=0;
	vector<int> I,J;
	for(i=1,j=0;i<=N;)
	{
		
		if(sum>=M)
		{
			
			if(sum-M<=minm)
			{
				if(sum-M<minm)
				{
					minm=sum-M;
					I.clear();
					J.clear();
				}
				I.push_back(i);
				J.push_back(j);
			}
			sum-=d[i++];
			
		}
		else
		{
			j++;
			sum+=d[j];
		}
	}
	for(unsigned int i=0;i<I.size();i++)
	{
		printf("%d-%d\n",I[i],J[i]);
	}
	return 0;
}
