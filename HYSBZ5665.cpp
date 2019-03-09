#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
const int MAXN = 1000005;
char s1[MAXN],s[MAXN*2];
int pal[MAXN*2];
int L[MAXN*2],R[MAXN*2];

int manacher()
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
	for(int i = 1;i <= len;i++){
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
	while(~scanf("%s",s1)){
		int len = manacher();
		
		for(int i = 1,maxr = 1;i < len;i++){
			if(pal[i]>1){
				int tr = i + pal[i] - 1;
				while(maxr <= tr) L[maxr++] = i;
			}
		}
		
		for(int i = len,minl = len;i >= 1;i--){
			if(pal[i]>1){
				int tl = i - pal[i] + 1;
				while(minl >= tl) R[minl--] = i;
			}
			
		}
		
	//	for(int i = 1;i <=len;i++) cout<<L[i]<<' ';cout<<endl;
	//	for(int i = 1;i <=len;i++) cout<<R[i]<<' ';cout<<endl;
		int ans = 0;
		for(int i = 1;i < len;i+=2){
			int l = R[i] - pal[R[i]] + 1;
			int r = L[i] + pal[L[i]] - 1;
			int cover = r-l; cout<<i <<'#'<<L[i]<<' '<<R[i]<<' '<<pal[R[i]]-1 + pal[L[i]]-1 - cover<<endl;
			ans = max(ans,pal[R[i]]-1 + pal[L[i]]-1 - cover);
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
