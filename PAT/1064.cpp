#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int ino[1005],ans[1005];
int N;
int getPos(int l,int r){
	int n = r - l + 1;
	int h = log(n+1)/log(2)+1; //cout<<"H:"<<h<<endl;
	int lrem = n - ((1<<(h-1)) - 1); //cout<<lrem<<' '<<((1<<(h-1))-2)/2<<endl;
	return l + ((1<<(h-1))-2)/2 + min(lrem,1<<(h-2)) ;
}
void leo(int index,int l,int r)
{
	if(index>N || l > r) return;
	int pos = getPos(l,r);//cout<<index<<' '<<l<<' '<<r<<' '<<pos<<endl;
	ans[index] = ino[pos];
	leo(index<<1,l,pos-1);
	leo(index<<1|1,pos+1,r); 
}
int main()
{
	scanf("%d",&N);
	for(int i = 1 ; i <= N;i++) scanf("%d",&ino[i]);
	sort(ino+1,ino+N+1);
	leo(1,1,N);
	printf("%d",ans[1]);
	for(int i = 2;i <= N;i++) printf(" %d",ans[i]);
	printf("\n"); 
	
	
	return 0;
}


