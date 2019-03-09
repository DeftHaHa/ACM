#include<stdio.h>
#include<string.h>
int main()
{
        int x,y,i,ans;
        int a[10],b[10],c[10];
        while(scanf("%d%d",&x,&y)&&(x||y)){
                memset(a,0,sizeof(a));memset(b,0,sizeof(b));memset(c,0,sizeof(c));//数组清零
                ans=0;
                i=0;
                while(x>0){a[i]=x%10;x/=10;i++;}
                i=0;
                while(y>0){b[i]=y%10;y/=10;i++;}                          //计算各个位上数
                for(i=0;i<10;i++){
                if(a[i]+b[i]+c[i]>9){ans++;c[i+1]=1;}
                else{c[i+1]=0;}
                }
        if(ans==0) printf("No carry operation.\n");
                else if(ans==1) printf("1 carry operation.\n");
                else printf("%d carry operations.\n",ans);
        }

        return 0;
}
