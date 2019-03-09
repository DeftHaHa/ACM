#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	long long n;
	while(cin>>n)
	{
		if((n-1)%3==0||(n-2)%3==0) cout<<"XiaoNiu"<<endl;
		else cout<<"XiaoKe"<<endl;
	}
	return 0;
}
/*
小牛和小客玩石子游戏，他们用n个石子围成一圈，小牛和小
客分别从其中取石子，谁先取完谁胜，每次可以从一圈中取一个
或者相邻两个，每次都是小牛先取，请输出胜利者的名字（小牛获
胜输出XiaoNiu，小客获胜输出XiaoKe）（1 2 3 4 取走 2 13 不算
相邻）

解法:对于大于2的石堆，先手取1或2个变成一个n-1或n-2的直线，
然后对手先去中间1或2个使剩下偶数个，接下去小牛怎么取小科就按
照中心对称取，小科必胜 
取则可赢。*/ 
