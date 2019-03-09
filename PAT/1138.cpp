#include<iostream>
#include<cstring>
#include<string>
using namespace std;
int N;
int pre[500005],in[500005];
bool flag = false;
void post(int pos,int l,int r){
	if(l > r || flag) return;
	int tag;
	for(int i = l;i <= r;i++){
		if(in[i] == pre[pos]){
			tag = i;
			break;
		}
	}
	post(pos+1,l,tag-1);
	post(pos+tag-l+1,tag+1,r);
	if(!flag){
		printf("%d",pre[pos]);
		flag = true;
	}
}
int main()
{
	scanf("%d",&N);
	for(int i = 0;i < N;i++) scanf("%d",&pre[i]);
	for(int i = 0;i < N;i++) scanf("%d",&in[i]);
	post(0,0,N-1);
	
	return 0;
}
