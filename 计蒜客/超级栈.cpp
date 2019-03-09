#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<deque>
using namespace std;
deque<int> q;
int main()
{
	int n;
	cin>>n;
	int c,num;
	bool dir=true;
	while(n--)
	{
		scanf("%d",&c);
		if(c==1) dir=!dir;
		else if(c==2)
		{
			if(dir) q.pop_front();
			else q.pop_back();
		}
		else if(c==3)
		{
			scanf("%d",&num);
			if(dir) q.push_front(num);
			else q.push_back(num);
		}
		else
		{
			int sz=q.size();
			if(!dir)
			{
				if(sz) printf("%d",q[0]);
				for(int i=1;i<sz;i++) printf(" %d",q[i]);
				printf("\n");
			}
			else
			{
				if(sz) printf("%d",q[sz-1]);
				for(int i=sz-2;i>=0;i--) printf(" %d",q[i]);
				printf("\n");
			}
		}
	}
	return 0;
}
