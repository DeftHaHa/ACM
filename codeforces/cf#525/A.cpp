#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	int x;
	int a,b;
	cin>>x;
	bool flag = false;
	for(int i = 1;i <= x;i++)
	{
		for(int j = 1;j <= x;j++)
		{
			if(i%j==0&&i*j>x&&i/j<x)
			{
				flag = true;
				cout<<i<<' '<<j<<endl;
				break;
			}
		}
		if(flag) break;
	}
	if(!flag) cout<<-1<<endl;
	return 0;
}
