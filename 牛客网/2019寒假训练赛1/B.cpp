#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[100005];
int main()
{
	int cnt[5] = {0,0,0,0,0};
	int n,x;
	cin>>n;
	for(int i = 0;i < n;i++){
		cin>>x;
		cnt[x]++;
	}
	int ans = 0;
	a[0] = 0;
	for(int i = 1;i <= n;i++){
		if(a[i-1] == 0){
			if(cnt[4]){
				a[i] = 4;
				cnt[4]--;
			}
			else if(cnt[2]){
				a[i] = 2;
				cnt[2]--;
			}
			else if(cnt[0]){
				a[i] = 0;
				cnt[0]--;
			}
		}
		else if(a[i-1] == 2){
			if(cnt[4]){
				a[i] = 4;
				cnt[4]--;
			}
			else if(cnt[0]){
				a[i] = 0;
				cnt[0]--;
			}
			else if(cnt[2]){
				a[i] = 2;
				cnt[2]--;
			}
		}
		else if(a[i-1] == 4){
			if(cnt[0]){
				a[i] = 0;
				cnt[0]--;
			}
			else if(cnt[2]){
				a[i] = 2;
				cnt[2]--;
			}
			else if(cnt[4]){
				a[i] = 4;
				cnt[4]--;
			}
		}
	//	cout<<a[i]<<' ';
		ans += (a[i]-a[i-1])*(a[i]-a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
} 
