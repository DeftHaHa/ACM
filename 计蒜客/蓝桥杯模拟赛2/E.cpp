#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int a[N][N];
int mx = 0, my = 0;
char f[N * N][N * N], p[10][10] ={
	"+---+**",
	"|   |/*",
	"|   | +",
	"+---+ |",
	"*/   /|",
	"**+---+",
};

void draw(int x, int y) {
	for (int i = 5; i >= 0; i--) {
		for (int j = 0; j < 7; j++) {
			if (p[i][j] == '*') {
				continue;
			}
			f[x+i][y+j] = p[i][j];
			mx = max(mx, x + i);
			my = max(my, y + j);
		}
	}
}


int main() {
	int n, m, x, y;
	cin >> n >> m;
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = 1; j <= m; j++) {
			for (int k = 1; k <= a[i][j]; k++) {
				draw(1 + 3 * (k - 1) + 2 * (i - 1), 1 + 4 * (j - 1) + 2 * (i - 1));
			}
		}
	}
	for (int i = mx; i >= 1; i--) {
		for (int j = 1; j <= my; j++) {
			if (f[i][j]) {
				cout << f[i][j];
			} else {
				cout << '.';
			}
		}
		cout << endl;
	}
	return 0;
}
