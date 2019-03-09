#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<stack>
using namespace std;
char s[100005];
int main()
{
	scanf("%s",s);
	int len = strlen(s);
	stack<char> S;
	S.push(s[0]);
	bool flag = false;
	for(int i = 1;i < len;i++){
		if(!S.empty() && S.top() == s[i]){
			S.pop();
			flag = !flag;
		}
		else S.push(s[i]);
	}
	if(flag) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
