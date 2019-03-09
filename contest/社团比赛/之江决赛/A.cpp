Description


qwb同时也是是之江学院的志愿者，暑期要前往周边地区支教，为了提高小学生的数学水平。她把小学生排成一排，从左至右从1开始依次往上报数。

玩完一轮后，他发现这个游戏太简单了。于是他选了3个不同的数x,y,z；从1依次往上开始报数，遇到x的倍数、y的倍数或z的倍数就跳过。如果x=2,y=3,z=5；第一名小学生报1，第2名得跳过2、3、4、5、6，报7；第3名得跳过8、9、10，报11。

那么问题来了，请你来计算，第N名学生报的数字是多少？

Input


多组测试数据，处理到文件结束。（测试数据数量<=8000）

每个测试例一行，每行有四个整数x,y,z,N。（ 2≤x,y,z≤107,1≤N≤1017）。

Output

对于每个测试例，输出第N名学生所报的数字，每个报数占一行。
Sample Input
2 3 5 2
6 2 4 10000

Sample Output
7
19999

#include<stdio.h>
#include<iostream>
using namespace std;
long long x,y,z,n;
long long xy,yz,xz,xyz;
long long gcd(long long a,long long b)
{
    long long temp;
    while(b)
    {
        /*利用辗除法，直到b为0为止*/
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
long long fn(long long nnn){
	return nnn/x+nnn/y+nnn/z-nnn/xy-nnn/yz-nnn/xz+nnn/xyz;
}
int main(){
	while(~scanf("%lld%lld%lld%lld",&x,&y,&z,&n)){
		long long ans,nn,tmpans;
		xy=x*y/gcd(x,y);
		yz=z*y/gcd(z,y);
		xz=x*z/gcd(x,z);
		xyz=xy*z/gcd(xy,z);
		long long incc;
		ans=n;
		incc=fn(n);
		while(incc){
			tmpans=ans;
			ans+=incc;
			incc=fn(ans)-fn(tmpans);
		}
		while(ans%x==0||ans%y==0||ans%z==0||ans-fn(ans)!=n)
				ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
