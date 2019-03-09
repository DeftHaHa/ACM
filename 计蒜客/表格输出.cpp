#include <stdio.h>
#include <string.h>
const int size = 12;
void print_table(const char *name, const char *course, const char *score) {
    const char *table[3] = {name, course, score};
    for (int i = 0; i < 3; ++i) {
        printf("|");
        int len = strlen(table[i]);
        int left_space = size-len-(size-len)/2;
        int right_space = (size-len)/2;
        for (int j = 0; j < left_space; ++j) {
            printf(" ");
        }
        printf("%s", table[i]);
        for (int j = 0; j < right_space; ++j) {
            printf(" ");
        }
    }
    printf("|\n");
    for (int i = 0; i < 3; ++i) {
        printf("+");
        for (int j = 0; j < size; ++j) {
            printf("-");
        }
    }
    printf("+\n");
}
int main() {
    for (int i = 0; i < 3; ++i) {
        printf("+");
        for (int j = 0; j < size; ++j) {
            printf("-");
        }
    }
    printf("+\n");
    print_table("name", "course", "score");
    print_table("barty", "math", "100");
    print_table("islands", "English", "60");
    print_table("wudi", "Chinese", "99");
    print_table("islands", "Physics", "100");
    return 0;
}
