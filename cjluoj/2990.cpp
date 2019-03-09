#include<iostream>
using namespace std;
int main()
{
        int n,m;
        while(cin>>n>>m)
        {
                if(m==0&&n==0) break;
                if(m%2==0||n%2==0)
                        cout<<"Wonderful!"<<endl;
                else
                        cout<<"What a pity!"<<endl;
        }
        return 0;
}
