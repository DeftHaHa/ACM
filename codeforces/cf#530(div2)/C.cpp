#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<string>
using namespace std;
int main()
{
	int k;
	string s;
	cin>>s>>k;
	int cnt1=0,cnt2=0;
	int len = s.length();
	for(int i = 0;i < len;i++)
	{
		if(s[i] == '?') cnt1++;
		else if(s[i] == '*') cnt2++;
	}
	int tot = len - cnt1 - cnt2;//cout<<tot << ' '<<cnt1<<' '<<cnt2<<endl; 
	if(!tot||(!cnt2 && tot < k)||(tot - cnt1 - cnt2 > k)) cout<<"Impossible"<<endl;
	else{
		string ans;
		if(tot < k){
			int t = k-tot;
			for(int i = 0;i < len;i++)
			{
				if(s[i]=='*'&&i>0&&s[i-1]!='*'&&s[i-1]!='?')
				{
					for(int j=0;j<t;j++) ans+=s[i-1];
					t=0;
				}
				else if(s[i]!='?'&&s[i]!='*') ans+=s[i];
			}
		}
		else{
			int t = tot - k;
			for(int i = 0;i < len;i++){
				if(s[i]!='*'&&s[i]!='?'){
					if(i<len-1&&(s[i+1]=='*'||s[i+1]=='?')&&t>0){
						t--;
					}
					else ans+=s[i];
				}
			}
		}
		if(ans.length()==k) cout<<ans<<endl;
		else cout<<"Impossible";
		cout<<endl;
	}
	return 0;
}
