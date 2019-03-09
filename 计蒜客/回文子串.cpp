#include<iostream>
#include<cstring>
#include<cstdio>
#include<set>
#include<string>
using namespace std;
struct cmp
{
	bool operator() (const string &a,const string &b)
	{
		return a<b;
	}
};
int main()
{
	string s;     
	cin>>s;      //string t(s.begin()+1,s.begin()+3); cout<<t<<endl;
	set<string,cmp> ans;
	int maxl=s.length();
	for(int i=0;i<maxl;i++)
	{
		int l=i,r=i;
		while(l>=0&&r<maxl&&s[l]==s[r])
		{
			string temp(s.begin()+l,s.begin()+r+1);  
			ans.insert(temp);
			l--;
			r++;
		}
		l=i;
		r=i+1;
		while(l>=0&&r<maxl&&s[l]==s[r])
		{
			string temp(s.begin()+l,s.begin()+r+1);//cout<<l<<" "<<r<<' '<<temp<<endl;
			ans.insert(temp);
			l--;
			r++;
		}
	}
	set<string>::iterator it;
	for(it=ans.begin();it!=ans.end();it++)
	{
		cout<<*it<<endl;
	}
	return 0;
}

