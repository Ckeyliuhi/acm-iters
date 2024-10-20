#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5;
constexpr i64 mod = 1e9 + 7;
i64 inv_fact[N], fact[N];
i64 power (i64 a, i64 b, i64 p = mod) {
    i64 res = 1;
    for ( ; b > 0; b >>= 1, a = a * a % p) {
        if (b & 1) res = res * a % p;
    }
    return res;
}

void init() {
    fact[0] = inv_fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv_fact[i] = power(fact[i], mod - 2);
    }
}

i64 C(int n, int k) {
    if (k > n) return 0;
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
}

void solve() { 
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    init(); 
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}