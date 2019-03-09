#include<iostream>
#include<stack>
using namespace std;
int main()
{
	int n;
	cin>>n;
	stack<int> S;
	int x;
	while(n--)
	{
		cin>>x;
		x%=2;
		if(!S.empty() && x == S.top()) S.pop();
		else S.push(x);
	}
	if(S.size() < 2) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
