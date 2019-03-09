#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
        int N,Q;
        int mar[105];
        int i,q;
        int c=1;
        while(cin>>N>>Q)
        {
                if(N==0&&Q==0) break;
                for(i=0;i<N;i++)
                        cin>>mar[i];
                sort(mar,mar+N);
                printf("CASE #%d\n",c++);
                while(Q--)
                {
                        cin>>q;
                        bool flag=false;
                        for(i=0;i<N;i++)
                                if(mar[i]==q)
                                {
                                        printf("%d found at %d\n",q,i);
                                        break;
                                }
                        if(i>=N) printf("%d not found\n",q);
                }
        }
        return 0;
}
