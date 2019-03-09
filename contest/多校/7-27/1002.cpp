#include<cstdio>
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
int main()
{
        int T;
        int N,X,Y;
        string d,a;
        int i;
        int tot;
        while(scanf("%d",&T)!=EOF)
        {
                while(T--)
                {
                        scanf("%d%d%d",&N,&X,&Y);
                        cin>>d>>a;
                        tot=0;
                        for(i=0;i<N;i++)
                        {
                              if(d[i]==a[i]) tot++;
                        }
                        if(abs(N-max(X,Y))<abs(min(X,Y)-tot)) printf("Lying\n");
                        else  printf("Not lying\n");
                }

        }
        return 0;
}
