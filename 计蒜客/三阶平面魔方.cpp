#include<cstdio>
#include<cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<set>
#include<queue>
using namespace std;
struct cube
{
	string s;
	int step;
};
cube m;
string M="123456789";
string now;
void left(int i)
{
	swap(now[i*3],now[i*3+2]);
	swap(now[i*3],now[i*3+1]);
}
void right(int i)
{
	swap(now[i*3],now[i*3+2]);
	swap(now[i*3+1],now[i*3+2]);
}
void up(int i)
{
	swap(now[i],now[6+i]);
	swap(now[i],now[3+i]);
}
void down(int j)
{
	swap(now[j],now[6+j]);
	swap(now[3+j],now[6+j]);
}
set<string> vis;
queue<cube> q;
int ans;
bool flag=false; int mx=0;
void bfs()
{
	q.push(m);
	vis.insert(m.s);
	m.step=0;
	while(!q.empty())
	{
		cube x=q.front(); //cout<<x.s<<endl;
		q.pop();
		for(int i=0;i<3;i++)
		{
			now=x.s;
			left(i);
			if(!vis.count(now))
			{
				vis.insert(now);
				cube next;
				next.step=x.step+1;
				next.s=now;
				q.push(next);
				if(now==M) 
				{
					ans=next.step;
					flag=true;
					return;
				}
			}
			now=x.s;
			right(i);
			if(!vis.count(now))
			{
				vis.insert(now);
				cube next;
				next.step=x.step+1;
				next.s=now;
				q.push(next);
				if(now==M) 
				{
					ans=next.step;
					flag=true;
					return;
				}
			}
			now=x.s;
			up(i);
			if(!vis.count(now))
			{
				vis.insert(now);
				cube next;
				next.step=x.step+1;
				next.s=now;
				q.push(next);
				if(now==M) 
				{
					ans=next.step;
					flag=true;
					return;
				}
			}
			now=x.s;
			down(i);
			if(!vis.count(now))
			{
				vis.insert(now);
				cube next;
				next.step=x.step+1;
				next.s=now;
				q.push(next);
				if(now==M) 
				{
					ans=next.step;
					flag=true;
					return;
				}
			}
		}
	}
}
int main()
{
	string x;
	cin>>x;m.s+=x;
	cin>>x;m.s+=x;
	cin>>x;m.s+=x;
	//cout<<m.s;
	bfs();
	if(flag) cout<<ans<<endl;
	else cout<<-1<<endl;
}
