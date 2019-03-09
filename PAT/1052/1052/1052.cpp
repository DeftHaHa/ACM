#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct Link
{
	int key,next;
}link[100005];
struct LINK
{
	int id,key;
};
bool cmp(const LINK &a,const LINK &b)
{
	return a.key<b.key;
}
int main()
{
	int N,s;
	cin>>N>>s;
	for(int i=0;i<N;i++)
	{
		int be,ne,key;
		scanf("%d%d%d",&be,&key,&ne);
		link[be].key=key;
		link[be].next=ne;
	}
	vector<LINK> v;
	int temp=s,tot=0;
	LINK x;
	while(temp!=-1)
	{
		x.id=temp;
		x.key=link[temp].key;
		v.push_back(x);
		temp=link[temp].next;
		tot++;
	}
	sort(v.begin(),v.end(),cmp);
	if(tot==0) {cout<<0<<' '<<-1<<endl;return 0;}
	printf("%d %05d\n",tot,v[0].id);
	for(int i=0;i<tot-1;i++)
	{
		printf("%05d %d %05d\n",v[i].id,v[i].key,v[i+1].id);
	}
	printf("%05d %d -1\n",v[tot-1].id,v[tot-1].key);
	return 0;
}