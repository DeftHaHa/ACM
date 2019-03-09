#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN = 1000005;
char s[MAXN],p[MAXN],lens,lenp;
int Next[MAXN];
void getNext(){
	Next[0] = -1;
	int k = -1;
	lens = strlen(s);
	for(int i = 1;i <= lens;i++){
		while(k > -1 && s[k+1] != s[i]) k = Next[k];
		if(s[k+1] == s[i]) k++;
		Next[i] = k;
	}
}
int KMP(){
	getNext();
	lenp = strlen(p);
	int ans = 0;
	int k = -1;
	for(int i = 0;i < lens;i++){
		while(k > -1 && p[k+1] != s[i]) k = Next[k];
		if(p[k+1] == s[i]) k++;
		if(k == lenp-1){
			ans++;//ÕÒµ½Ò»¸ö 
		}
	}
	return ans;
}
int main()
{
	while(~scanf("%s",s))
	{
		if(s[0] == '#') return 0;
		scanf("%s",p);
		printf("%d\n",KMP());
	}
	return 0;
}
