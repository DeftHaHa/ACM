#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

string a, b;
int f[10010];

int lcs() {
    memset(f, 0, sizeof f);
    for (int i = 0; i < a.size(); ++i) {
        for (int j = 0, ans = 0; j < b.size(); ++j) {
            int tmp = f[j];
            if (a[i] == b[j]) {
                f[j]=max(ans+1,f[j-1]);
            }
            else if ( j - 1 > 0 ) {
                f[j] = max(f[j], f[j - 1]);
            }
            ans = tmp;
        }
    }
    return f[b.size() - 1];
}

int main() {
    cin >> a >> b;
    cout << lcs() << endl;
}
