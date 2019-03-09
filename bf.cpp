#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1000005;
char s1[MAXN],s[MAXN*2];
int pal[MAXN*2];
int manacher(int l)
{
	s[0] = '$';
	s[1] = '#';
	int len = 2;
	for(int i = 0;i < l;i++){
		s[len++] =  s1[i];
		s[len++] =  '#';
	}
	s[len] = '@';
	
	int Max = 0;
	int pos = 1,right = -1;
	for(int i = 1;i < len;i++){
		if(i > right) pal[i] = 1;
		else pal[i] = min(pal[2*pos-i],right-i+1);
		while(s[i-pal[i]] == s[i+pal[i]]) pal[i]++;
		if(i + pal[i] - 1 > right){
			pos = i;
			right = i + pal[i] -1;
		}
	}
	return len;
}
int main()
{
	freopen("data.in","r",stdin);
	freopen("data.ans","w",stdout);
	
	int l;
	while(~scanf("%d%s",&l,s1))
	{
		int len = manacher(l);
		int ans = 0;
 		for(int i = 1;i < len;i += 2){
            for(int k = (pal[i] - 1) / 4;k > 0;k--){
                int pos = i + k*2;
                if(pal[pos] - 1 >= 2*k){
                    ans = max(ans,k * 4);
                    break;
                }
            }
        }
		printf("%d\n",ans);
	}
	return 0;
}
