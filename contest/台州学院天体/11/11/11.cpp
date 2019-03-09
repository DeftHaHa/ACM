#include<iostream>
#include<cstdio>
using namespace std;
int father[10005];
int get(int x)
{
	if(father[x]==x) return x;
	return father[x]=get(father[x]);
}
void merge(int a,int b)
{
	a=get(a);
	b=get(b);
	if(a!=b) father[a]=b;
}
int main()
{

	return 0;
}