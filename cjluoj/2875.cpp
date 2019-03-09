#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
        int a,b,c,d;
        int m,n;
        while(cin>>a>>b>>c>>d)
        {
                m=min(a,c);
                m=min(m,d);
                a-=m;
                n=min(a,b);
                cout<<256*m+32*n<<endl;
        }
        return 0;
}
