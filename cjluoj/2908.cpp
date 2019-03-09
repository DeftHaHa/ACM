#include<cstring>
#include<iostream>
using namespace std;
int main()
{
        int N,M;
        int a[10000];
        int i;
        while(cin>>N>>M)
        {
                memset(a,0,sizeof(0));
                for(i=1;i<=N;i++)
                        cin>>a[i];
                M%=N;
                for(i=N-M+1;i<=2*N-M;i++)
                {
                        if(i<=N) cout<<a[i];
                        else cout<<a[i-N];
                        if(i<2*N-M) cout<<' ';
                }
                cout<<endl;
        }
        return 0;
}
