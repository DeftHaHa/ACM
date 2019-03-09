#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
bool is_prime[500005];
int main()
{
	memset(is_prime,true,sizeof(is_prime));
	int tot=0;
	for(int i=2;i<=sqrt(250000);i++)
    {
            if(is_prime[i])
            {
                    for(int j=i*i;j<=250000;j+=i)
                    {
                            is_prime[j]=false;
                    }
            }
    }
	int N,n;
	cin>>N;
	while(N--)
	{
		scanf("%d",&n);
		int ans=1;
		for(int i=2;i<n;i++)
		{
			if(is_prime[i]&&n%i==0) {ans+=i;}
		}
		printf("%d\n",ans);
	}
	return 0;
}