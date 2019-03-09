#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<queue>
#include<cstdlib> 
using namespace std;
int main()
{
	int a[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	for(int i = 1;i < 13;i++)
	{
		int cnt = 0,sum = 0;
		do{
			cnt++;
			int temp = a[0],len = 1;
			for(int j = 1;j < i;j++)
			{
				if(a[j] > temp)
				{
					temp = a[j];
					len++;
				}
			}
			sum += len;
		}
		while(next_permutation(a,a+i));
		cout<<(double)sum/(double)cnt<<endl;
	}
	return 0;
}
