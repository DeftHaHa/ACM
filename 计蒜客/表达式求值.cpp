#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
const int N = 1e3 + 7;
const int inf = 0x3f3f3f3f;
char str[N];
stack<int> num;
stack<char> op;
int priority(char c) {
    if (c == '*') {
        return 2;
    }
    if (c == '+') {
        return 1;
    }
    return 0;
}
void calculate() {
    int suma = 0, sumb = 0;
    int b = num.top();
    num.pop();
    int a = num.top();
    num.pop();
    switch (op.top()) {
    case '+':
        num.push(a + b);
        break;
    case '*':
        num.push(a * b);
        break;
    case 'S':
        while (b != 0) {
            sumb += b % 10;
            b /= 10;
        }
        while (a != 0) {
            suma += a % 10;
            a /= 10;
        }
        num.push(max(suma, sumb));
        break;
    }
    op.pop();
}
int main() {
    int i, j, t, n, m, tt = 0, tmp;
    freopen("DATA.txt","r",stdin);
    scanf("%d", &t);
    while (t--) {
        scanf("%s", str);
        while (!op.empty()) {
            op.pop();
        }
        while (!num.empty()) {
            num.pop();
        }
        int len = strlen(str);
        for (i = 0; i <= len; i++) {
            if (isdigit(str[i])) {
                sscanf(str + i, "%d%n", &tmp, &n);
                i += n - 1;
                num.push(tmp);
            }
            else if (str[i] == '(') {
                op.push(str[i]);
            }
            else if (str[i] == ')') {
                while (op.top() != '(') {
                    calculate();
                }
                op.pop();
            }
            else if (str[i] == 'S') {
                op.push('(');
                op.push('S');
                i += 4;
            }
            else if (str[i] == ',') {
            }
            else if (str[i]=='*') {
                op.push(str[i]);
            }
            else {
                while (!op.empty() && priority(str[i]) <= priority(op.top())) {
                    calculate();
                }
                op.push(str[i]);
            }
        }
        printf("%d\n", num.top());
    }
    return 0;
}
