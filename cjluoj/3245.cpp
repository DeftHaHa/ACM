#include<iostream>
#include<stdlib.h>
#include<string>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
        string s;
        int n;
        while(cin>>n)
        {
                s.clear();
                itoa(n,s,16);
                cout<<s<<endl;
        }
        return 0;
}
