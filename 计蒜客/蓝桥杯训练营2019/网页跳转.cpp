#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<stack>
using namespace std;
stack<string> S1,S2;
int main()
{
	int n;
	char oper[10],s[105];
	scanf("%d",&n);
	while(n--){
		scanf("%s",oper);
		if(oper[0] == 'V'){
			scanf("%s",s);
			S1.push(s);
			printf("%s\n",s);
			while(!S2.empty()) S2.pop();
		}
		else if(oper[0] == 'B'){
			if(S1.size() <= 1){
				printf("Ignore\n");
				continue;
			}
			S2.push(S1.top());
			S1.pop();
			printf("%s\n",S1.top().c_str());
		}
		else{
			if(S2.empty()){
				printf("Ignore\n");
				continue;
			}
			S1.push(S2.top());
			printf("%s\n",S1.top().c_str());
			S2.pop();
		}
	}
	return 0;
}
