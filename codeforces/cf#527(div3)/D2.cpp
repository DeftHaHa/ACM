#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	cin>>n;
	stack<int> S;
	int x,Max = -1;
	while(n--)
	{
		cin>>x;
		Max = max(x,Max);
		if(!S.empty() && x == S.top()) S.pop();
		else
		{
			if(!S.empty() && x > S.top())
			{
				cout<<"NO"<<endl;
				return 0;
			}
			S.push(x);
		}
	}
	if((S.size() == 1 && S.top() == Max)||!S.size()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
