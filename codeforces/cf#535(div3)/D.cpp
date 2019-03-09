#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 200005;
char s[maxn];
int main()
{
	int n;
	scanf("%d%s",&n,s);
	char Next[256];
	Next['R'] = 'G',Next['G'] = 'B',Next['B'] = 'R';
	int cnt = 0;
	for(int i = 1;i < n;i++){
		if(s[i]==s[i-1]){
			s[i] = Next[s[i]];
			if(s[i]==s[i+1]) s[i] = Next[s[i]];
			cnt++;
		}
	}
	printf("%d\n",cnt);
	puts(s);
	return 0;
}
