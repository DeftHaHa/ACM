#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string,map<string,int> > Map;
int main()
{
	int N;
	char s1[105],s2[105];
	scanf("%d",&N);
	int n;
	while(N--){
		scanf("%s%s%d",s1,s2,&n);
		Map[s2][s1]+=n;
	}
	for(map<string,map<string,int> >::iterator it = Map.begin();it != Map.end();it++){
		printf("%s\n",it->first.c_str());
		for(map<string,int>::iterator it2 = it->second.begin();it2 != it->second.end();it2++){
			printf("   |----%s(%d)\n",it2->first.c_str(),it2->second);
		}
	}
	
	return 0;
}
