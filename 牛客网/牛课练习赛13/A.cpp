#include<iostream>
#include<cstdio>
#include<cstdio>
#include<set>
#include<map>
#include<string>
using namespace std;
map<string,int> mp;
int main()
{
	string s;
	while(cin>>s)
	{
		mp.clear();
		int l=s.length();
		string temp;
		for(int i=0;i<l;i++)
		{
			if(s[i]=='4'||s[i]=='7')
			{
				temp.clear();
				temp+=s[i];
				mp[temp]++;
				for(int j=i+1;j<l;j++)
				{
					if(s[j]=='4'||s[j]=='7')
					{
						temp+=s[j];
						mp[temp]++; 
					}
				}
				
			}
		}
		int maxcnt=0;
		string ans;
		map<string,int>::iterator it;
		for(it=mp.begin();it!=mp.end();it++)
		{         
			if(it->second>maxcnt)
			{
				ans=it->first;
				maxcnt=it->second;
			}
		}
		if(maxcnt) cout<<ans<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}
