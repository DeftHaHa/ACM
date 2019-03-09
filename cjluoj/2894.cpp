#include<iostream>
using namespace std;
int main()
{
        int a[55][55],b[55][55];
        int c[55][55];
        int i,j;
        int m,n;
        while(cin>>m>>n)
        {
                if(m==-1&&n==-1) break;
                for(i=1;i<=m;i++)
                {
                        for(j=1;j<=n;j++)
                                cin>>a[i][j];
                }
                for(i=1;i<=n;i++)
                {
                        for(j=1;j<=m;j++)
                                cin>>b[i][j];
                }
                for(i=1;i<=m;i++)
                {
                        for(j=1;j<=m;j++)
                        {
                                c[i][j]=0;
                                for(int k=1;k<=n;k++)
                                {
                                        c[i][j]+=a[i][k]*b[k][j];
                                }

                                cout<<c[i][j];
                                if(j<m) cout<<' ';
                        }
                        cout<<endl;
                }
        }
        return 0;
}
