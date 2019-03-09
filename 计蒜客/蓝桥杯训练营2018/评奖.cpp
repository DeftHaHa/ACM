#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct STU
{
	string name;
	int sum;
};
bool cmp(STU a,STU b)
{
	return a.sum>b.sum;
} 
int main()
{
	int N;
	int a,b,c,d;
	cin>>N;
	STU stu[45];
	for(int i=0;i<N;i++)
	{
		cin>>stu[i].name>>a>>b>>c>>d;
		stu[i].sum = a+b+c+d;
	}
	sort(stu,stu+N,cmp);
	for(int i = 0;i<3;i++) cout<<stu[i].name<<endl;
	return 0;
}
