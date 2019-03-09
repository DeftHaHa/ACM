#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue> 
using namespace std;
queue<int> q;
bool inq[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		memset(inq,false,sizeof(inq));
		int a,Size = 0;
		int ans = 0;
		while(!q.empty()) q.pop();
		while(N--)
		{
			scanf("%d",&a);
			//for(int i =0 ;i<1000;i++) if(inq[i]) cout<<i<<' ';cout<<"##"<<endl;
			if(!inq[a])
			{
				if(!q.empty() && Size == M){
					inq[q.front()] = false;
					q.pop();
					Size--;
				}
				q.push(a);
				inq[a] = true;
				Size++;
				ans++; 
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
