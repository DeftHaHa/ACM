#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int N;
	int n[105];
	cin>>N;
	for(int i=N-1;i>=0;i--) scanf("%d",&n[i]); ///传递给左边所以反向 
	bool same=false;
	int ans=0,temp;
	while(1)
	{ 
		same=true;
		int t=n[0];
		for(int i=1;i<N;i++) 
			if(n[i]!=t)
			{
				same=false;
			}
		if(same) break;
		temp=n[N-1];
		for(int i=0;i<N;i++)
		{
			int x=n[i];
			n[i]=x/2+temp/2;
			temp=x;
		}
		for(int i=0;i<N;i++)
			if(n[i]&1)
			{
				n[i]++;
				ans++;
			}
	}
	cout<<ans<<endl;
	return 0;
}
