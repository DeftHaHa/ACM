#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef long long ll;
const int N = 1e5 + 10;
ll a[N], f[N];

void merges(ll l, ll m, ll r) {
    ll i = l, j = m + 1, n = r, k = 0; //cout<<' '<<l<<' '<<r<<endl;
    while (i <= m &&j <= n) {  
        if ((i<=m&&a[i]<a[j])||j>=n) {  
            f[k++] = a[i++];
        }
        else {
            f[k++] = a[j++];
        }
    }
    for (i = 0; i < k; ++i) {
        a[l + i] = f[i];
    }
}

void merge_sort(ll l, ll r) {
    if (l < r) {
        ll m = (l + r )>> 1;
        merge_sort(l, m);
        merge_sort(m + 1, r);
        merges(l, m, r);
    }
}

int main() {
    ll n;
    freopen("DATA.txt","r",stdin);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    merge_sort(0, n - 1);
    for (int i = 0; i < n; ++i) {
        cout << a[i] << endl;
    }
}
