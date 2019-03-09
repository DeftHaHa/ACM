#include<stdio.h>
#include<string.h>
int main()
{       int x,y,i,j;
        char a[200][200];
        char n,b;
        char z='A';

        scanf("%d%d",&x,&y);
        n=getchar();
        if(n=='\n'){
         while((scanf("%c",&n)!=EOF)){
                        z='A';
           for(i=0;i<x;i++){
             for(j=0;j<y;j++){

                if((n>=97)&&(n<=122))
                {
                                a[i][j]=n-32;
                }
                else if((n>=65)&&(n<=90))
                {
                                a[i][j]=n;            //给第i行填充输入的字符,并转化小写为大写
                }
                else if(n=='\n') break;
                else j--;
                n=getchar();
              }
              if(n=='\n') break;                    //输入回车i行输入完毕
           }

        for(i;i<x;i++){
                for(j;j<y;j++){
                        a[i][j]=z;
                        z++;
                        if(z>'Z') z='A';
                }
                j=0;
        }                                             //i行剩下的循环填充字母ABCD...
        for(j=0;j<y;j++){
                for(i=0;i<x;i++){
                        printf("%c",a[i][j]);
                }
        }
        printf("\n");                                 //输出
   }}
        return 0;
}
