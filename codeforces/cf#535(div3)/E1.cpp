#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
const int maxn = 305;
int a[maxn];
int l[maxn],r[maxn];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int Max = 0xc0c0c0c0;
	for(int i = 0;i < n;i++){
		scanf("%d",&a[i]);
		if(a[i] > Max) Max = a[i];
		Maxl[i] = a[i];
	}
	Max = 0xc0c0c0c0;
	for(int i = n-1;i >= 0;i--){
		if(a[i] > Max) Max = a[i];
		Maxr[i] = a[i];
	}
	for(int i = 0;i < m;i++){
		scanf("%d%d",&l[i],&r[i]);
	}
	for(int i = 0;i < n;i++){
		int Max = 0xc0c0c0c0,Min = 0x3f3f3f3f;
		int posmax,posmin;
		for(int j = 0;j < n;j++){
			if(a[j] > Max) Max = a[j],posmax = j;
			if(a[j] < Min) Min = a[j],posmin = j;
		}
		for(int j = 0;j < m;j++){
			
		}
	}
	return 0;
}
