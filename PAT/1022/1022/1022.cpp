#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<vector>
#include<cstdio>
#include<algorithm>
using namespace std;
struct book
{
	string id;
	string title;
	string author;
	vector<string> key;
	string publisher;
	string year;
}b[10005];
bool cmp(const string &a,const string &b)
{
	return a<b;
}
int main()
{
	int N;
	char ch;
	while(cin>>N)
	{
		ch=getchar();
		for(int i=0;i<N;i++)
		{
			cin>>b[i].id;
			ch=getchar();
			getline(cin,b[i].title);
			getline(cin,b[i].author);
			string a;
			getline(cin,a);
			stringstream ss(a);
			while(ss>>a) b[i].key.push_back(a);
			getline(cin,b[i].publisher);
			cin>>b[i].year;
		}
		int M;
		cin>>M;
		ch=getchar();
		string s,ask;
		while(M--)
		{
			getline(cin,ask);
			
			cout<<ask<<endl;
			s.clear();
			vector<string> ans;
			vector<string>::iterator it;
			for(int i=3;i<ask.size();i++) s+=ask[i];
			bool flag=false;
			if(ask[0]=='1')
			{
				for(int i=0;i<N;i++)
				{
					if(b[i].title==s)
					{
						flag=true;
						ans.push_back(b[i].id);
					}
				}
			}
			else if(ask[0]=='2')
			{
				for(int i=0;i<N;i++)
				{
					if(b[i].author==s)
					{
						flag=true;
						ans.push_back(b[i].id);
					}
				}
			}
			else if(ask[0]=='3')
			{
				for(int i=0;i<N;i++)
				{
					
					for(it=b[i].key.begin();it!=b[i].key.end();it++)
					{
						if(*it==s)
						{
							flag=true;
							ans.push_back(b[i].id);
							break;
						}
					}
				}
			}
			else if(ask[0]=='4')
			{
				for(int i=0;i<N;i++)
				{
					if(b[i].publisher==s)
					{
						flag=true;
						ans.push_back(b[i].id);
					}
				}
			}
			else if(ask[0]=='5')
			{
				for(int i=0;i<N;i++)
				{
					if(b[i].year==s)
					{
						flag=true;
						ans.push_back(b[i].id);
					}
				}
			}
			if(!flag) cout<<"Not Found"<<endl;
			else
			{
				sort(ans.begin(),ans.end(),cmp);
				for(it=ans.begin();it!=ans.end();it++)
					cout<<*it<<endl;
			}
		}
	}
	return 0;
}