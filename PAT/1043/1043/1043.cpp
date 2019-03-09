#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int pre[1005],post[1005];
int N,tot;
void bst(int r,int left,int right)
{
	if(left>right) return;
	int i,root=pre[r];
	for(i=left+1;i<=right;i++) if(pre[i]>=root) break;
	for(int j=i;j<=right;j++) if(pre[j]<root) return;
	bst(r+1,r+1,i-1);
	bst(i,i,right);
	post[tot++]=root;
}
void mbst(int r,int left,int right)
{
	if(left>right) return;
	int i,root=pre[r];
	for(i=left+1;i<=right;i++) if(pre[i]<root) break;
	for(int j=i;j<=right;j++) if(pre[j]>=root) return;
	mbst(r+1,r+1,i-1);
	mbst(i,i,right);
	post[tot++]=root;
}
int main()
{
	
	
	cin>>N;
	for(int i=0;i<N;i++) cin>>pre[i];
	tot=0;
	bool flag=false;
	bst(0,0,N-1);
	if(N==tot)
	{
		cout<<"YES"<<endl;
		cout<<post[0];
		for(int i=1;i<tot;i++) cout<<' '<<post[i];
		cout<<endl;
		flag=true;
	}
	else
	{
		tot=0;
		mbst(0,0,N-1);
		if(tot==N)
		{
			cout<<"YES"<<endl;
			cout<<post[0];
			for(int i=1;i<tot;i++) cout<<' '<<post[i];
			cout<<endl;
			flag=true;
		}
	}
	if(!flag) cout<<"NO"<<endl;
	return 0;
}
