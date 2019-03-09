#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100005],pos[100005];
int main()
{
	int N,x,y;
	scanf("%d%d%d",&N,&x,&y);
	int l,r,mx,mi;
	for(int i = 1;i <= N;i++){
		scanf("%d",&a[i]);
		pos[a[i]] = i;
	}
	l = pos[x],r = pos[y];
	if(l>r) swap(l,r);
	int nl = l,nr = r;
	mx = mi = x;
	for(int i = l;i <= r;i++){
		mx = max(a[i],mx);
		mi = min(a[i],mi);
	}
	for(int i = mi;i <= mx;i++){
		nl = min(pos[i],nl);
		nr = max(pos[i],nr);
	}
	while(nr - nl != mx - mi){
		//printf("%d( %d %d )%d  %d-%d\n",nl,l,r,nr,mi,mx);
		int tmi = mi,tmx = mx;
		for(int i = nl;i < l;i++){
			mx = max(a[i],mx);
			mi = min(a[i],mi);
		}
		for(int i = r+1;i <=nr;i++){
			mx = max(a[i],mx);
			mi = min(a[i],mi);
		}
		l = nl,r = nr;
		for(int i = mi;i < tmi;i++){
			nl = min(pos[i],nl);
			nr = max(pos[i],nr);
		}
		for(int i = tmx+1;i <= mx;i++){
			nl = min(pos[i],nl);
			nr = max(pos[i],nr);
		}
		
	}
	cout<<nl<<' '<<nr<<endl;
	return 0;
}
/*
5 2 3
2 5 1 3 4
*/
