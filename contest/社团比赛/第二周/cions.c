#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,z,v,n,coin;
    long long a[10010];
	scanf("%d",&z);
	while(z--){
		memset(a,0,sizeof(a));
		scanf("%d%d",&v,&n);
		a[0]=1;
		for(i=0;i<v;i++){
			scanf("%d",&coin);
                        for(j=0;j<=n-coin;j++)
                                if(a[j]>0) a[j+coin]=a[j+coin]+a[j];
		}
		printf("%lld\n",a[n]);
	}
    return 0;
}
