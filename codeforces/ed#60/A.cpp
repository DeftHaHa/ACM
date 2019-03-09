#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
typedef long long ll;
int a[100005];
int main()
{
	int n;
	scanf("%d",&n);
	int Max = 0,pos = -1;
	for(int i = 1;i <= n;i++){
		scanf("%d",&a[i]);
		if(a[i] > Max){
			Max = a[i];
			pos = i;
		}
	}
	int ans = 0;
	for(int i = 1;i <= n;i++){
		if(a[i] == Max){
			int j = i;
			while(j+1<=n && a[j+1]==Max) j++;
			//cout<<i <<' '<<j<<' '<<Max<<endl;
			ans = max(ans,j-i+1);
			i = j;
		}
	}
	printf("%d\n",ans);
	return 0;
}
