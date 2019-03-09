#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
        int n;
        double num[10];
        int i,j;
        while(cin>>n)
        {
                if(n==0) break;
                while(n--)
                {
                        for(i=0;i<8;i++) cin>>num[i];
                        sort(num,num+8);
                        printf("%.2f",num[0]);
                        for(i=1;i<8;i++) printf(" %.2f",num[i]);
                        cout<<endl;
                }
        }
        return 0;
}
