#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 200005;
char s[7][maxn];
char ch[7][3] = 
{
	{},
	{'R','G','B'},
	{'R','B','G'},
	{'G','R','B'},
	{'G','B','R'},
	{'B','R','G'},
	{'B','G','R'}
};
int main()
{
	int n;
	scanf("%d%s",&n,s[0]);
	int cnt[7];
	memset(cnt,0,sizeof(cnt));
	for(int i = 0;i < n;i++){
		int pos = i%3;
		for(int j = 1;j <= 6;j++){
			if(s[0][i]!=ch[j][pos]) cnt[j]++;
		}	
	}
	int tag = 1,Min = cnt[1];
	for(int i = 2;i <= 6;i++){
		if(cnt[i]<Min){
			tag = i;
			Min = cnt[i];
		}
	}
	printf("%d\n",cnt[tag]);
	for(int i = 0;i < n;i++){
		printf("%c",ch[tag][i%3]);
	}
	printf("\n");
	return 0;
}
