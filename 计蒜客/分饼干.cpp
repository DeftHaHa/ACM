#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	for(int x=899;x<=100000000;x++)
	{
		if(x%113==60&&x%233==150&&x%666==233)
		{
			cout<<x<<endl;
		}
	}
	return 0;
}
