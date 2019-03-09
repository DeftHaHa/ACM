#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
	int x[20]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	char str[20];
	char M[]={'1','0','X','9','8','7','6','5','4','3','2'};
	int ans=0;
	while(scanf("%s",str)!=EOF)
	{
		int sum=0;
		for(int i=0;i<17;i++)
		{  
			if(str[i]=='X') sum+=10*x[i];
			else sum+=(str[i]-'0')*x[i]; 
		}
		sum%=11;
		if(M[sum]!=str[17])
		{   
			ans++;
		}cout<<"==="<<ans<<endl;
	}
	return 0;
}
