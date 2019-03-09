#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<set>
using namespace std;
set<string> Set;
int toLow(char s[]){
	int len = strlen(s);
	for(int i = 0;i < len;i++){
		if(s[i]>=97) s[i]-=32;
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int x;
	char s[25];
	while(n--){
		scanf("%d%s",&x,s);
		toLow(s);
		if(!x) Set.insert(s);
		else printf("%s\n",Set.count(s) ? "Yes":"No");
	}
	return 0;
}
