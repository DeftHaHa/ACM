#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int a[3];
	a[0] = a[1] = a[2] = 0; 
	for(int i = 0 ;i < s.length();i++)
	{
		if(s[i]=='R') a[0]++;
		else if(s[i] == 'G') a[1]++;
		else a[2] ++;
	}
	int cnt = min(min(a[0]/1,a[1]/2),a[2]/3);
	//for(int i = 0;i < cnt;i++) printf("BBBGGR");
	sort(s.begin(),s.end());
	cout<<s;
	printf("\n%d\n",cnt);
	return 0;
}
