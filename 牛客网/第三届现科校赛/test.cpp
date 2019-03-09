#include<iostream>
#include<string>
using namespace std;
string ans[1000005],my[1000005];
int main()
{
	int pos = 0;
	freopen("j.out","r",stdin);
	while(getline(cin,ans[pos++]))
	{
		cout<<ans[pos-1]<<endl;
	}
	fclose(stdin);
	pos = 0;
	freopen("j.out","r",stdin);
	fclose(stdin);
	while(getline(cin,my[pos++]))
	{
		cout<<ans[pos-1]<<endl;
	}
	for(int i = 0;i < pos;i++)
	{
		if(ans[i]!=my[i])
		{
			cout<<i<<' '<<ans[i]<<'#'<<my[i]<<endl;
		}
	}
	return 0;
}
