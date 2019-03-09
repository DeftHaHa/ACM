#include<iostream>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
int main()
{
	int N,M,Q;
	cin>>M>>N>>Q;
	stack<int> s;
	while(Q--)
	{
		int n[1005],now=0;
		for(int i=0;i<N;i++) scanf("%d",&n[i]);
		bool flag=true;
		while(!s.empty()) s.pop();
		int i=1;
		while(now<N)
		{
			
			while(!s.empty()&&s.top()==n[now])
			{
				s.pop();
				now++;
				
			}
			if(s.empty()||s.top()!=n[now])
			{
				s.push(i);
				i++;
			}
			if(s.size()>M) {flag=false;break;}
		}
		if(flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}