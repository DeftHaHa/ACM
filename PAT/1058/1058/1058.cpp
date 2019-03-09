#include<iostream>
using namespace std;
int main()
{
	int n1,n2,n3;
	int m1,m2,m3;
	scanf("%d.%d.%d",&n1,&n2,&n3);
	scanf("%d.%d.%d",&m1,&m2,&m3);
	int ans1=0,ans2=0,ans3=0;
	ans3=n3+m3;
	if(ans3>28)
	{
		ans3%=29;
		ans2+=1;
	}
	ans2=ans2+n2+m2;
	if(ans2>16)
	{
		ans2%=17;
		ans1+=1;
	}
	ans1=ans1+n1+m1;
	printf("%d.%d.%d\n",ans1,ans2,ans3);
	return 0;
}