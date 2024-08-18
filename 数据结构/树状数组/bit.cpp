#include <bits/stdc++.h>

using namespace std;
using i64 = long long;
constexpr int N = 1e5 + 5;
int n, m, a[N]; 
 
struct Fenwick {
    i64 tree[N];

    int lowbit (int x) {
        return x & -x;
    }

    void add (int x, i64 val) {
        for ( ; x <= n + 1; x += lowbit(x)) {
            tree[x] += val;
        }
    }

    i64 ask (int x) {
        i64 res = 0;
        for ( ; x; x -= lowbit(x)) {
            res += tree[x];
        }
        return res;
    }

    i64 query (int l, int r) {
        return ask (r) - ask (l - 1);
    }
} bit;

void solve() {  

}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    // freopen("C:/Users/26842/Desktop/acm/in.txt", "r", stdin);
    int _ = 1;
    // cin >> _;
    while (_--) {
        solve();
    }
    return 0;
}
