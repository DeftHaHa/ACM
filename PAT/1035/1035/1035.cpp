#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
int main()
{
	string name[1005],pass[1005];
	int N;
	cin>>N;
	
	vector<int> ans;
	for(int i=0;i<N;i++)
	{
		cin>>name[i]>>pass[i];
		bool flag=false;
		for(unsigned int j=0;j<pass[i].size();j++)
		{
			if(pass[i][j]=='1') {flag=true;pass[i][j]='@';}
			else if(pass[i][j]=='l') {flag=true;pass[i][j]='L';}
			else if(pass[i][j]=='0') {flag=true;pass[i][j]='%';}
			else if(pass[i][j]=='O') {flag=true;pass[i][j]='o';}
		}
		if(flag) ans.push_back(i);
	}
	if(ans.size()!=0)
	{
		cout<<ans.size()<<endl;
		for(unsigned int i=0;i<ans.size();i++)
		{
			cout<<name[ans[i]]<<' '<<pass[ans[i]]<<endl;
		}
	}
	else if(N==1) {printf("There is 1 account and no account is modified\n");}
	else printf("There are %d accounts and no account is modified\n",N);
	return 0;
}