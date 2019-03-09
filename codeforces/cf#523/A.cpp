#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int n,s;
	while(cin>>n>>s)
	{
		if(n>=s) cout<<1<<endl;
		else if(s%n!=0) cout<<s/n+1<<endl;
		else cout<<s/n<<endl;
	}
	
	return 0;
}
