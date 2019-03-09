#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int a[100005];
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		int x,odd = 0;
		for(int i = 0 ; i < n;i++)
		{
			scanf("%d",&a[i]);
			if(a[i]&1) odd++; 
		}
		if(a[0] == 1 && n==1){
			printf("Alice\n");
			continue;
		}
		int even = n-odd;
		if(even&1 && odd&1) printf("Alice\n");
		else if(even&1) printf("Alice\n");
		else if(odd&1) printf("Bob\n"); 
		else printf("Alice\n"); 
	}	
}
