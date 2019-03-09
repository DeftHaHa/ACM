#include<iostream>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
stack<int> Stack;
int ans1[25005],ans2[25005],cnt = 0;
char s[50005];
int main()
{
	scanf("%s",s);
	int len = strlen(s);
	bool flag = true;
	for(int i = 0;i < len;i++){
		if(s[i]=='(') Stack.push(i+1);
		else{
			if(Stack.empty()){
				flag = false;
				break;
			}
			ans1[cnt] = Stack.top();
			Stack.pop();
			ans2[cnt++] = i+1;
		}
	}
	if(flag && Stack.empty()){
		cout<<"Yes"<<endl;
		for(int i = 0;i < cnt;i++){
			printf("%d %d\n",ans1[i],ans2[i]);
		}
	}
	else cout<<"No"<<endl;
	return 0;
}
