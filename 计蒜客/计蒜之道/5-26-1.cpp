#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int T;
	cin>>T;
	int n;
	while(T--)
	{
		scanf("%d",&n);
		if(n&1) printf("%d ",18+(n/2)*12-n);
		else
		{
			int a=n;
			int mint=0x3f3f3f3f;
			int x=(int)pow(a,1.0/3);
			for(int i=x+1;i>0;i--)
			{
				if(a%i==0)
				{
					int y=(int)sqrt(a/i);
					int aa=a/i;
					for(int j=y+1;j>0;j--)
					{
						if(aa%j==0)
						{
							mint=min(mint,(aa/j+2)*(j+2)*(i+1));
						}
					}
				}
			}
			printf("%d ",mint-n);
			
		}
		printf("%d\n",(n+1)*9-n);
	}
	return 0;
}
