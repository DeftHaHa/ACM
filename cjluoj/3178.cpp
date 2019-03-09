#include<iostream>
#include<cstdio>
using namespace std;
int bgcd(int x,int y)
{
        if(y==0) return 0;
        else return 1+bgcd(y,x%y);
}
int main()
{
        int x,d,y0,y1;
        while(scanf("%d%d%d%d",&x,&d,&y0,&y1)!=EOF)
        {
                int tot=0;
                for(int i=y0;i<=y1;i++)
                {
                        if(bgcd(x,i)==d) tot++;
                }
                printf("%d\n",tot);
        }
        return 0;
}
