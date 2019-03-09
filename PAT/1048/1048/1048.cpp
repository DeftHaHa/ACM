#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int N,M;
	cin>>N>>M;
	int c[100005];
	for(int i=0;i<N;i++) scanf("%d",&c[i]);
	sort(c,c+N);
	int j=lower_bound(c,c+N,M)-c;
	int i=0;
	j-=1;
	int ans1=0x3f3f3f3f,ans2;
	while(i<j)
	{
		int sum=c[i]+c[j];
		if(sum<=M)
		{
			if(sum==M)
			{
				ans1=c[i];
				ans2=c[j];
				break;
			}
			i++;
		}
		else j--;
	}
	if(ans1==0x3f3f3f3f) printf("No Solution\n");
	else printf("%d %d\n",ans1,ans2);
	return 0;
}