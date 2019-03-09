#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int f[N], a[N];
int n;
int find(int l, int r, int x) {
	while (l < r) {
		int mid = (l + r) / 2;
		if (f[mid] < x) {
			l = mid + 1;
		} else {
			r = mid;
		}
	}
	return l;
}
int lis() {
	int len = 0;
	for (int i = 0; i < n; i++) {
		int k = find(0,len,a[i]);
		f[k] = a[i];
		if (k == len) {
			len++;
		}
	}
	return len;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", a + i);
	}
	printf("%d\n", lis());
	return 0;
}
