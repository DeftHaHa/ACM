#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int a[N];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	for (int i = 100; i >= 0; i--) {
		while(a[i]--) {
			cout << i << endl;
		}
	}
	return 0;
}
