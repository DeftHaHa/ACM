#include <iostream>
#include <string>
using namespace std;
int whatday(int y, int m, int d) {
	//ÿ���1/2�·�Ҫ������һ���13 14�·� 
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
    return (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;//�˼���ʽ 
}
string weekday[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
int main() {
    int y, m, d;
    cin >> y >> m >> d;
    cout << weekday[whatday(y, m, d)] << endl;
    return 0;
}
