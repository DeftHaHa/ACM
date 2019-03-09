#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
map<string,int> Map;
int main()
{
	string s;
	getline(cin,s);
	int len = s.length();
	string now = "";
	int Max = 0;
	string ans;
	bool ok = false;
	for(int i = 0;i < len;i++){
		if(s[i]>='a' && s[i]<='z') now += s[i]; 
		else if(s[i]>='A' && s[i]<='Z') now += (char)(s[i]+32);
		else if(s[i]>='0'&& s[i]<='9') now += s[i]; 
		else ok = true;
		if(ok || i == len-1&&!ok){
			if(now != "" ){
				Map[now]++;
				int cnt = Map[now]; //cout<<now<<' '<<cnt<<endl;
				if(cnt > Max){
					Max = cnt;
					ans = now;
				}
				else if(cnt == Max && now < ans) ans = now;
			}
			now = "";
			ok = false;
		}
	}
	printf("%s %d\n",ans.c_str(),Max);
	return 0;
}
