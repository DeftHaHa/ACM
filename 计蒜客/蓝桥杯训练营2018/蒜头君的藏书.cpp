#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string,int> Map;
int main()
{
	int n;
	char s[105];
	scanf("%d",&n);
	while(n--)
	{
		scanf("%s",s);
		Map[s]++;
	}
	printf("%d\n",Map.size());
	for(map<string,int>::iterator it = Map.begin();it!=Map.end();it++){
		printf("%s %d\n",it->first.c_str(),it->second);
	}
	return 0;
}
