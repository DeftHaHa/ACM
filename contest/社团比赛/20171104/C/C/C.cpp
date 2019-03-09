#include<iostream>
#include<string>
#include<cstdio>
#include<map>
#include<cstring>
using namespace std;
int main()
{
	int T;
	int n,m;
	map<string,int> stu;
	int tot[1005];
	cin>>T;
	while(T--)
	{
		memset(tot,0,sizeof(tot));
		stu.clear();

		cin>>n>>m;
		string name;
		int id,p;
		while(n--)
		{
			cin>>name;
			scanf("%d%d",&id,&p);
			if(p==1) tot[id]++;
			stu.insert(pair<string,int>(name,id));
		}
		bool ans=true;
		string Q;
		while(m--)
		{
			cin>>Q;
			int x=stu[Q];
			if(tot[x]<=0) ans=false;
			tot[x]--;
		}
		if(ans) printf("excited\n");
		else printf("I am angry\n");
	}
	return 0;
}