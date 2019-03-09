#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
char s1[110005],s[220005];
int pal[220005];
int manacher(char s1[])
{
	int l = strlen(s1);
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
		else pal[i] = min(pal[2*pos-i],right-i+1);//¹ØÓÚpos¶Ô³Æ 
		while(s[i-pal[i]] == s[i+pal[i]]) pal[i]++;
		if(i + pal[i] - 1 > right){
			pos = i;
			right = i + pal[i] -1;
		}
		Max = max(Max,pal[i]-1);
	}
	return Max;
}
int main()
{
	while(~scanf("%s",s1)){
		printf("%d\n",manacher(s1));
	}
	return 0;
}
