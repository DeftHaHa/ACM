Description


qwb又遇到了一道题目：

有一个序列，初始时只有两个数x和y，之后每次操作时，在原序列的任意两个相邻数之间插入这两个数的和，得到新序列。举例说明：
初始：1 2
操作1次：1 3 2
操作2次：1 4 3 5 2
……
请问在操作n次之后，得到的序列的所有数之和是多少？

Input


多组测试数据，处理到文件结束（测试例数量<=50000）。

输入为一行三个整数x，y，n，相邻两个数之间用单个空格隔开。（0 <= x <= 1e10, 0 <= y <= 1e10, 1 < n <= 1e10）。

Output

对于每个测试例，输出一个整数，占一行，即最终序列中所有数之和。
如果和超过1e8，则输出低8位。（前导0不输出，直接理解成%1e8）


Sample Input
1 2 2

Sample Output
15
#include<stdio.h>
using namespace std;

const long long midModNum = 1000000000;
const long long modNum    = 100000000;
long long qPow(long long a,long long b){
  long long r=1;
  while(b){
    if(b&1) r=r*a%midModNum;
    a=a*a%midModNum;
    b>>=1;
  }
  return r;
}
int main(){
	long long x,y,n,ans;
	while(~scanf("%lld%lld%lld",&x,&y,&n)){
		ans=0;
		ans=qPow(3,n)+1;
		ans/=2;
		ans=ans*(x+y)%modNum;
		printf("%lld\n",ans);
	}

	return 0;
}
