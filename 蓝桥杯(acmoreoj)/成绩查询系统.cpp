#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	map<string,int> stu;
	int score[1005];
	int cnt=0;
	string s,name;
	int n;
	while(1)
	{
		cin>>s;
		if(s[0]=='e') break;
		else
		{
			cin>>name;
			
			if(s[0]=='i')
			{
				scanf("%d",&n); char ch=getchar();
				if(!stu.count(name))
				{
					stu[name]=++cnt;
					score[cnt]=n;
				}
				else
				{
					score[stu[name]]=max(score[stu[name]],n);
				}
			}
			else
			{
				if(stu.count(name))
				{
					printf("%d\n",score[stu[name]]);
				}
				else printf("-1\n");
			}
		}
	}
	return 0;
}
