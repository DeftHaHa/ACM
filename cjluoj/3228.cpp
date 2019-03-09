#include<iostream>
using namespace std;
int main()
{
        int n;
        while(cin>>n)
        {
                if(n<0) break;
                if(n>=100) cout<<"Buy it!!!"<<endl;
                else cout<<"Buy another!!!"<<endl;
        }
        return 0;
}
