#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<map>
#include<string>
using namespace std;
int r = 4e8; 
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int Count(int n){
	int len = sqrt(n),res = 0;
	for(int i = 1;i < len;i++){
		if(n%i==0) res+=2;
	}
	return res;
}
int main()
{
	freopen("data.txt","w",stdout);
	int cnt = 0;
	for(int i = 2;i <= r;i++){
		for(int j = 2;j <= r;j++){
			if(gcd(i,j) == 1){
				
				if(Count(i*j) > 10){
					printf("%d %d\n",i,j);
					cnt++;
					if(cnt==2005) return 0;
				}
				
			}
		}
	}
	return 0;
} 
