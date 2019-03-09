#include <iostream>
#include <string>
using namespace std;
int whatday(int y, int m, int d) {
	//每年的1/2月份要当成上一年的13 14月份 
	if(m==1)
	{
		y--;
		m = 13;
	}
	else if(m==2)
	{
		m=14;
		y--;
	}
    return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//菜鸡公式 
}
string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    cout << weekday[whatday(y, m, d)] << endl;
    return 0;
}
