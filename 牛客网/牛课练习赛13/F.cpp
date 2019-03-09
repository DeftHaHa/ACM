#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
bool visr[100005],visc[100005];
int r[100005],c[100005];
void init()
{
	memset(visr,0,sizeof(visr));
	memset(visc,0,sizeof(visc));
}
int main()
{
	int n,m;
    while(~scanf("%d%d",&n,&m))
    {
    	for(int i=0;i<m;i++)
    	{
    		scanf("%d%d",&r[i],&c[i]);
    		visr[r[i]]=true;
    		visc[c[i]]=true;
		}
	}
    return 0;
}
