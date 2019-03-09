#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
struct node
{
	int id,next;
	char s;
	bool vis;
}n[100005];
int main()
{
	int a1,a2,N;
	while(cin>>a1>>a2>>N)
	{
		int id,next;
		while(N--)
		{
			scanf("%d",&id);
			char ch=getchar();
			scanf("%c %d",&n[id].s,&n[id].next);
			n[id].vis=false;
		} 
		int t=a1;
		while(t!=-1)
		{
			n[t].vis=true;
			t=n[t].next;
		}
		t=a2;
		while(t!=-1)
		{
			if(n[t].vis) break;
			t=n[t].next;
		}
		if(t!=-1) printf("%05d\n",t);
		else cout<<-1<<endl;
	}
	return 0;
}