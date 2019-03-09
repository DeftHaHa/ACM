#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
vector<long int> v;
int main()
{
	int N1,N2;
	cin>>N1;
	long int n1,n2;
	for(int i=0;i<N1;i++) {scanf("%ld",&n1);v.push_back(n1);}
	cin>>N2;
	for(int i=0;i<N2;i++) {scanf("%ld",&n2);v.push_back(n2);}
	sort(v.begin(),v.end());
	cout<<v[(N1+N2-1)/2]<<endl;
	return 0;
}