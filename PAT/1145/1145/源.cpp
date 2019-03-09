#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
bool is_prime(int n)
{
	if(n<2) return false;
	for(int i=2;i<=sqrt(n);i++)
	{
		if(n%i==0) return false;
	}
	return true;
}
int main()
{
	int table[200005];
	int Msize,N,M;
	cin>>Msize>>N>>M;
	int Tsize=1;
	for(int i=Msize;;i++)
	{
		if(is_prime(i))
		{
			Tsize=i;
			break;
		}
	}
	memset(table,-1,sizeof(table));
	int num;
	while(N--)
	{
		cin>>num;
		bool flag=false;
		for(int i=0;i<Tsize;i++)
		{
			int Hkey=(num+i*i)%Tsize;
			if(table[Hkey]==-1)
			{
				table[Hkey]=num;
				flag=true;
				break;
			}
		}
		if(!flag) printf("%d cannot be inserted.\n",num);
	}
	//for(int i=0;i<Tsize;i++) cout<<table[i]<<' ';cout<<endl;
	int tot=0;
	int T=M;
	while(T--)
	{
		cin>>num;
		bool flag=false; // cout<<num<<"===="<<endl;
		for(int i=0;i<Tsize;i++)
		{
			int Hkey=(num+i*i)%Tsize;
			tot++;  //cout<<table[Hkey]<<' ';
			if(table[Hkey]==num||table[Hkey]==-1)
			{
				flag=true;
				break;
			}
		}
		if(!flag) tot++;// cout<<endl;
	}
	printf("%.1lf\n",(double)tot/(double)M);
	system("pause");
	return 0;
}