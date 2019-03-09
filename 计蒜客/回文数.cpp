#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main()
{
	int N;
	cin>>N;
	vector<int> ans;
	while(1)
	{
		ans.push_back(N);
		int temp=N,Next=0;
		while(temp)
		{
			Next=Next*10+temp%10;
			temp/=10;
		}
		if(Next==N) break;
		N+=Next;
	}
	printf("%d\n",ans.size()-1);
	printf("%d",ans[0]);
	for(int i=1;i<ans.size();i++) printf("--->%d",ans[i]);
	printf("\n");
	return 0;
}
