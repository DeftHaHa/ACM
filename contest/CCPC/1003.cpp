#include <iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool map[3005][3005];
int n;
int main()
{
        int T;

        int i,j;
        int temp;
        scanf("%d",&T);
        while(T--)
        {
                scanf("%d",&n);
                memset(map, false, sizeof(map));
                for(i=1;i<=n-1;i++)
                {
                        for(j=1;j<=n-i;j++)
                        {
                                scanf("%d",&temp);
                                if(temp==0) continue;
                                else if(temp==1)
                                {
                                        map[i][j+i]=true;
                                        map[i+j][i]=true;
                                }
                        }
                }
                bool flag=true;
                for(i=1;i<=n;i++)
                {
                        if(flag)
                        for(j=i+1;j<=n;j++)
                        {
                                if(flag)
                                for(int k=j+1;k<=n;k++)
                                {
                                        int court=0;
                                        if(map[i][j])
                                                court++;
                                        if(map[i][k])
                                                court++;
                                        if(map[j][k])
                                                court++;
                                        if(court==3||court==0)
                                        {
                                                flag=false;
                                                break;
                                        }
                                }
                        }
                }
                if(flag) printf("Great Team!\n");
                else printf("Bad Team!\n");
        }
        return 0;
}
