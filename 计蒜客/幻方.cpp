#include <stdio.h>
int vis[40];
int num[6][6];
int ok(int n) {
    int avg = (n * n + 1) * n * n / 2 / n;
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += num[i][j];
        }
        if (sum != avg) {
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        int sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += num[j][i];
        }
        if (sum != avg) {
            return 0;
        }
    }
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += num[i][i];
    }
    if (sum != avg) {
        return 0;
    }
    sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += num[i][n - i - 1];
    }
    if (sum != avg) {
        return 0;
    }
    return 1;
}
int dfs(int x, int y, int n) {
    if (x == n) {
        return ok(n);
    }
    if (x >= 1 && y == 0) {
        int s = 0;
        for (int i = 0; i < n; ++i) {
            s += num[x - 1][i];
        }
        if (n * s != (n * n + 1) * n * n / 2) {
            return 0;
        }
    }
    for (int i = 1; i <= n * n; ++i) {
        if (vis[i] == 0) {
            vis[i] = 1;
            num[x][y]=i;;
            int success = dfs(x + (y == n - 1?1 : 0), (y + 1) % n, n);
            if (success) {
                return 1;
            }
            vis[i]=0;
        }
    }
    return 0;
}
void magic_square(int n) {
    for (int i = 1; i <= n * n; ++i) {
        vis[i] = 0;
    }
    if (dfs(0, 0, n)) {
        printf("%d阶幻方如下\n", n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                printf("%d%c", num[i][j], j == n - 1? '\n' : ' ');
            }
        }
    } else {
        printf("找不到%d阶幻方\n", n);
    }
    printf("\n");
}
int main() {
    magic_square(1);
    magic_square(2);
    magic_square(3);
    magic_square(4);
    return 0;
}
