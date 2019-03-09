#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
using namespace std;
int main()
{
        char ch;
        int N;
        int ans;
        while(cin>>N>>ch)
        {
                if(N&1) ans=N*(N+1)/2;
                else  ans=N*N/2;
                cout<<ch<<':'<<ans<<endl;
        }
        return 0;
}
