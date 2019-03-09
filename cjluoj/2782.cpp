#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
        char p[10][10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
        int i,j;
        char n[100005]={'\0'};
        while(scanf("%s%*c",n)!=EOF)
        {
                i=0;
                if(n[0]=='0')
                {
                        printf("ling\n");
                        continue;
                }
                else if(n[0]=='-')
                        i=1;
                if(i) printf("fu ");
                printf("%s",p[n[i]-'0']);
                i+=1;
                for(;n[i]!='\0';i++)
                {
                        printf(" ");
                        printf("%s",p[n[i]-'0']);
                }
                printf("\n");
                memset(n,'\0',sizeof(n));
        }
        return 0;
}
