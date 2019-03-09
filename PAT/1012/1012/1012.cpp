#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;
struct student
{
	string name;
	int a,c,m,e;
}s[2005];
bool cmp(const int &a,const int &b)
{
	return a>b;
}
int main()
{
	int N,M;
	char ans[5]={'\0','A','C','M','E'};
	int cc[2005],mm[2005],ee[2005],aa[2005];
	while(cin>>N>>M)
	{
		for(int i=0;i<N;i++)
		{
			cin>>s[i].name;
			scanf("%d%d%d",&cc[i],&mm[i],&ee[i]);
			aa[i]=(cc[i]+mm[i]+ee[i])/3;
			s[i].c=cc[i];
			s[i].m=mm[i];
			s[i].e=ee[i];
			s[i].a=aa[i];
		}
		sort(aa,aa+N,cmp);
		sort(cc,cc+N,cmp);
		sort(mm,mm+N,cmp);
		sort(ee,ee+N,cmp);
		string q;
		while(M--)
		{
			cin>>q;
			int i,j;
			for(i=0;i<N;i++)
			{
				if(q==s[i].name) break;
			}
			if(i>=N) cout<<"N/A"<<endl;
			else
			{
				int flag;
				for(j=0;j<N;j++)
				{
					if(s[i].a==aa[j])
					{
						flag=1;
						break;
					}
					else if(s[i].c==cc[j])
					{
						flag=2;
						break;
					}
					else if(s[i].m==mm[j])
					{
						flag=3;
						break;
					}
					else if(s[i].e==ee[j])
					{
						flag=4;
						break;
					}
				}
				printf("%d %c\n",j+1,ans[flag]);
			}
		}
	}
	return 0;
}