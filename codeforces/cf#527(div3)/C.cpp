#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
bool judge(string a,string b,int len){
	for(int i = 0;i < len;i++){
		if(a[i] != b[i]) return false;
	}
	return true;
}
int main()
{
	int n;
	cin>>n;
	string b,e;
	bool flag = false;
	string s[205];
	int len[205];
	for(int i = 0;i < 2*n-2;i++){
		cin>>s[i];
		len[i] = s[i].length();
		if(len[i] == n-1){
			if(!flag){b = s[i];flag = true;}
			else e = s[i];
		}
	}
	// ǰ׺���n-2�ͺ�׺ǰ��n-2���Ƿ���ͬҲҪ�ж�,���ܳ��֡����� abbb �����Ԥ��bbbΪǰ׺��ƥ������ҲΪn-1 
	if(b.substr(1,n-1) != e.substr(0,n-2)) swap(b,e); 
	int sum = 0;
	int group[205],vis[205]; // len-i
	memset(group,0,sizeof(group));
	memset(vis,0,sizeof(vis));
	for(int i = 0;i < 2*n-2;i++){
		if(judge(b,s[i],len[i]) && !vis[len[i]]){
			group[i] = vis[len[i]] = 1;
			sum ++;
		}
	}
	//���ܽ���ǰ׺���n-2�ͺ�׺ǰ��n-2����ͬ ȷ��ǰ��׺����baba abab �����ababaҲ�����babab 
	if(sum != n-1)	
	{
		swap(b,e);
		memset(group,0,sizeof(group));
		memset(vis,0,sizeof(vis));
		for(int i = 0;i < 2*n-2;i++){
			if(judge(b,s[i],len[i]) && !vis[len[i]]){
				group[i] = vis[len[i]] = 1;
				sum ++;
			}
		}
	}
	for(int i = 0;i < 2*n-2;i++)
	{
		if(group[i]) printf("P");
		else printf("S");
	}
	cout<<endl;
	return 0;
}
