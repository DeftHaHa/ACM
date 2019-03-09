#include<iostream>
#include<cstdio>
using namespace std;
int a[15][15];
int t;
int i,j;
void pf(int n)
{
        for(i=j;i<=n+1-j;i++)
        {
                a[i][n+1-j]=++t;
                if(t==n*n) return;
        }
        for(i=n-j;i>=j;i--)
        {

                a[n+1-j][i]=++t;
                if(t==n*n) return;
        }
        for(i=n-j;i>=j;i--)
        {
                a[i][j]=++t;
                if(t==n*n) return;
        }
        for(i=j+1;i<=n-j;i++)
        {
                a[j][i]=++t;
                if(t==n*n) return;
        }
        j++;
        pf(n);
}
int main()
{

        int n;
        while(cin>>n)
        {
                t=0;
                j=1;
                pf(n);
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=n;j++)
                        {
                                printf("%4d",a[i][j]);
                        }
                        cout<<endl;
                }
        }
        return 0;
}
