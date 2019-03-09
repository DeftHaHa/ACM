#include <stdio.h>

void christmas_tree(int n) {
    for (int i = 1; i <= n; ++i) { // ??????
        for (int j = 1; j <= n; ++j) { // ?????
            int space_cnt =  3*n-2*i-j; // ??????
            int tree_cnt = 4*(i-1)+1+2*(j-1) ; // ??????
            for (int k = 0; k < space_cnt; ++k) {
                putchar(' ');
            }
            for (int k = 0; k < tree_cnt; ++k) {
                putchar('*');
            }
            putchar('\n');
        }
    }
    for (int i = 1; i < 3 * (n - 1); ++i) {
        putchar(' ');
    }
    puts("***");
    for (int i = 1; i < 3 * (n - 1); ++i) {
        putchar(' ');
    }
    puts("***");
    for (int i = 1; i < 3 * (n - 1); ++i) {
        putchar(' ');
    }
    puts("***");
}

int main() {
    christmas_tree(6);
    return 0;
}
