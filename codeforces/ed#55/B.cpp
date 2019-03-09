#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int n;
	string s;
	cin>>n>>s;
	int ans=0,now=0,tot=0,pre=0;
	for(int i=0;i<n;i++){
        if(s[i]=='G'){
            now++;
			tot++;
        }
        else {
            pre=now;
            now=0;
        }
        ans=max(ans,pre+now+1);
	}
	cout<<min(ans,tot)<<endl;
	return 0;
}
