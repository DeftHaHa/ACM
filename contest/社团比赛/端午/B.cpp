#include<cstdio>
#include<cstring>
int main()
{
        int N;
        int total;
        float h;
        char ch;
        while(scanf("%d",&N)!=EOF)
        {
                if(N==0) break;
                total=0;
                while(N)
                {
                        ch=getchar();
                        if(ch-'0'>=0&&ch-'0'<=9)
                        {
                                N--;
                                scanf("%f",&h);
                                h+=(ch-'0');
                                if(h==1.75) total++;
                        }
                }
                printf("%d\n",total);
        }
        return 0;
}
