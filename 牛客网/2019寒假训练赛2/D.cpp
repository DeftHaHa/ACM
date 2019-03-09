#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	int n;
	int ans = 0;
	scanf("%d",&n);
	int num;
	while(n--){
		scanf("%d",&num);
		if(num<60) ans+=400;
	}
	printf("%d\n",ans);
	return 0;
}
