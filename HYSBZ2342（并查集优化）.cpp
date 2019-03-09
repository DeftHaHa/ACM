#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAXN = 1000005;
char s1[MAXN],s[MAXN*2];
int pal[MAXN*2];
int fa[MAXN*2];
int getfa(int x){ return fa[x] == x ? x : fa[x] = getfa(fa[x]);} 
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
	for(int i = 5;i < len-5;i++){
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
	int l;
	while(~scanf("%d%s",&l,s1))
	{
		int len = manacher(l);
 		for(int i = 1;i < len;i++){
 			if(s[i]=='#') fa[i] = i; 
 			else fa[i] = i + 1;
		}
		int ans = 0;
		for(int i = 5;i < len;i+=2){
			int pos = getfa(i - pal[i]/4-2);  //从i-pal[i]/2开始 
			while(pos < i && pos + pal[pos] < i) //找到最远覆盖或者一直未找到停止 
			{
				pos = getfa(pos+1); //更新下一跳 ,跳跃到下一跳
			}
			if(pos < i) ans = max(ans,2*(i-pos));
			
		}
		printf("%d\n",ans);
	}
	return 0;
}
