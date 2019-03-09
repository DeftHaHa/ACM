#include <stdio.h>
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}
ll mul(ll a, ll b, ll mod)
{
    ll res = 0;
    while(a)
    {
        if(a & 1) res = (res + b) % mod;
        b = (2 * b) % mod;
        a >>= 1;
    }
    return res;
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        long long a, b, mod;
        scanf("%lld%lld%lld", &a, &b, &mod);
        if(b % 2 == 0)
            printf("%lld\n", (mul(a-1,b/2,mod) + (a + gcd(a,b))/2) % mod);
        else
            printf("%lld\n", (mul(a-1,(b+1)/2,mod) + (gcd(a,b)+1)/2) % mod);
    }

    return 0;
}