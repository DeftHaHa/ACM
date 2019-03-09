Description


做完了辣么多的数学题，qwb好好睡了一觉。但是他做了一个梦：

有一个n*m的矩阵，qwb在这个矩阵的左上角(1,1)，终点在右下角(n,m)。
每个格子中有小钱钱，也可能没有，还有可能是要交过路费的，并且行走方向必须是靠近终点的方向。
往下走一次只能走一格，往右走一次可以走一格也可以走到当前列数的倍数格。
比如当前格子是（x,y），那么可以移动到(x+1,y),(x,y+1)或者(x,y*k),其中k>1。

qwb希望找到一种走法，使得到达右下角时他能够有最多的小钱钱。

你能帮助他吗？

Input

第一行是测试例数量 T （T<=100），接下来是T组测试数据。
每组测试数据的第一行是两个整数n,m，分别表示行数和列数(1<=n<=20,1<=m<=10000)；
接下去给你一个n*m的矩阵，每个格子里有一个数字 k （-100<=k<=100）代表小钱钱的数量。 ∑nm<=3,000,000



Output

每组数据一行，输出L先生能够获得小钱钱的最大值(可能为负数)。

Sample Input
1
3 8
9 10 10 10 10 -10 10 10
10 -11 -1 0 2 11 10 -20
-11 -11 10 11 2 10 -10 -10

Sample Output 52

#include<iostream>
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int T,nn,mm;
int a[20][10000];
int ans[20][10000];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&nn,&mm);
		for(int i=0;i<nn;i++)
			for(int j=0;j<mm;j++){
				scanf("%d",&a[i][j]);
				ans[i][j]=-30000000;
			}
		ans[0][0]=0;
		for(int i=0;i<nn;i++){
			for(int j=0;j<mm;j++){
				if(i) ans[i][j]=max(ans[i-1][j],ans[i][j]);
				if(j) ans[i][j]=max(ans[i][j-1],ans[i][j]);
				ans[i][j]+=a[i][j];
				for(int k=2;k<=mm/(j+1);k++){
					ans[i][k*(j+1)-1]=max(ans[i][k*(j+1)-1],ans[i][j]);
				}
			}
		}
		printf("%d\n",ans[nn-1][mm-1]);
	}
	return 0;
}
