#include<iostream>
#include<cstring>
#include<string>
#include<cstdio>
using namespace std;
int main()
{
	int order[55],K;
	char ch[5]={'S','H','C','D','J'};
	cin>>K;
	int ans[55],temp[55];
	for(int i=1;i<=54;i++) {cin>>order[i];ans[i]=i;}
	while(K--)
	{
		swap(ans,temp);
		for(int i=1;i<=54;i++)
		{
			ans[order[i]]=temp[i];
		}
	}
	cout<<ch[ans[1]/13]<<ans[1]%13;
	for(int i=2;i<=54;i++)
	{
		ans[i]-=1;
		cout<<' '<<ch[ans[i]/13]<<ans[i]%13+1;
	}
	cout<<endl;
	return 0;
}