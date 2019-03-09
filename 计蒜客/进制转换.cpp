#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;

int olds, news;
char olddata[N], newdata[N];

void swit() {
	long long n = 0, flag = 1;
	for (int i = 0; olddata[i]; ++i) {
		if (olddata[i] == '-') {
			flag = -1;
		}
		else if(olddata[i] > '9') {
			n = n * olds + olddata[i] - 55;
		}
		else {
			n = n * olds + olddata[i] - '0';
		}
	}
	n *= flag;
	string s;
	int tmp = 0;
	while(n != 0) {
		tmp = n % news;
		n /= news;
		if (tmp >= 10) {
			s = char(tmp + 55) + s;
		}
		else {
			s=char('0'+tmp)+s;
		}
	}
	for (int i = 0; s[i]; ++i) {
		newdata[i] = s[i];
	}
}

int main() {
	cin >> olds >> news;
	cin >> olddata;
	swit();
	cout << newdata << endl;
	return 0;
}
