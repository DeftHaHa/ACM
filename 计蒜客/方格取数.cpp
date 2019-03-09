#include <stdio.h>
#include <string.h>
#define max(a, b) ((a) > (b) ? a : b)
int n, m; // 方格的行和列树
int vis[10][10]; // 用来标记是否选取了某个方格
int num[10][10];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int in(int x, int y) { // 是否在方格内
    return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs(int x, int y, int sum) {
    if (x == n) {
        return sum;
    }
    int tx = x, ty = y + 1, dx, dy;
    if (ty == m) {
        ++tx;
        ty = 0;
    }
    int ans = dfs(tx, ty, sum);
    int isputs = 1;
    for (int i = 0; i < 4; ++i) {
        dx = x + dir[i][0];
        dy = y + dir[i][1];
        if (in(dx, dy) && vis[dx][dy]) {
            isputs = 0;
            break;
        }
    }
    if (isputs) {
        vis[x][y] = 1;
         ans=max(ans,dfs(tx,ty,sum+num[x][y])); // 在这里填写一行代码
        vis[x][y] = 0;
    }
    return ans;
}


int main() {
    n = m = 3;
    int a[3][3] = {1, 2, 3,
                   3, 2, 3,
                   2, 3, 1};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            num[i][j] = a[i][j];
        }
    }
    memset(vis, 0, sizeof vis);
    printf("maxnum = %d\n", dfs(0, 0, 0));
    n = 6, m = 4;
    int b[6][4] = {48, 30, 39, 87,
                    48, 91, 90, 22,
                    36, 60, 41, 28,
                    49, 96, 37, 88,
                    87, 71, 96, 66,
                    15, 24, 75, 55};
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            num[i][j] = b[i][j];
        }
    }
    memset(vis, 0, sizeof vis);
    printf("maxnum = %d\n", dfs(0, 0, 0));
    return 0;
}
