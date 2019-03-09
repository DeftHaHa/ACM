#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	char ch[]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
	string ans[3];
	int s[3];
	cin>>s[0]>>s[1]>>s[2];
	for(int i=0;i<3;i++)
	{
		if(s[i]==0) ans[i]="00";
		while(s[i]>0)
		{
			ans[i]=ch[s[i]%13]+ans[i];
			s[i]/=13;
		}
		if(ans[i].length()==1) ans[i]='0'+ans[i];
	}
	cout<<'#'<<ans[0]<<ans[1]<<ans[2]<<endl;
	return 0;
}