#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int n[10005];
vector<int> num;
int main()
{
	memset(n,0,sizeof(n));
	int N,t;
	cin>>N;
	while(N--)
	{
		scanf("%d",&t);
		n[t]++;
		num.push_back(t);
	}
	for(unsigned int i=0;i<num.size();i++)
	{
		if(n[num[i]]==1)
		{
			cout<<num[i]<<endl;
			return 0;
		}
	}
	cout<<"None"<<endl;
	return 0;
}