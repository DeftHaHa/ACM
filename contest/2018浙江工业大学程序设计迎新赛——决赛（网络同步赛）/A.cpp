#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N,M;
		cin>>N>>M;
		string s;
		cin>>s;
		int cnt = 0;
		for(int i = 0;i < N;i++) if(s[i] == '*') cnt++;
		if(N - cnt > M || (!cnt && N < M)) cout<<"*yitu*"<<endl;
		else
		{
			bool flag = true;
			for(int i = 0;i < N;i++)
			{
				if(s[i] == '*'&&flag){
					flag =false;
					for(int j = 0;j < M-N+cnt;j++) printf("a");
				}
				else if(s[i] != '*') printf("%c",s[i]);	
			}
			cout<<endl;
		}
		
	}
	return 0;
}
