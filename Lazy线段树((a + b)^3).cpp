#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t; 

constexpr int N = 1e5 + 5;
constexpr i64 mod = 1e9 + 7;
i64 a[N];
struct SegTree {
    int l, r;
    i64 sum1, sum2, sum3, lazy;
} seg[N << 2];

void pushup (int rt) {
    seg[rt].sum1 = (seg[rt << 1].sum1 + seg[rt << 1 | 1].sum1) % mod;
    seg[rt].sum2 = (seg[rt << 1].sum2 + seg[rt << 1 | 1].sum2) % mod;
    seg[rt].sum3 = (seg[rt << 1].sum3 + seg[rt << 1 | 1].sum3) % mod;
}

void build (int l, int r, int rt) {
    seg[rt].l = l, seg[rt].r = r;
    if (l == r) {
        seg[rt].sum1 = a[l];
        seg[rt].sum2 = a[l] * a[l] % mod;
        seg[rt].sum3 = a[l] * a[l] % mod * a[l] % mod;
        seg[rt].lazy = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, rt << 1);
    build (mid + 1, r, rt << 1 | 1);
    pushup(rt);
} 

void check (int rt, i64 c) {
    int len = seg[rt].r - seg[rt].l + 1;
    seg[rt].sum3 = (seg[rt].sum3 + len * c % mod * c % mod * c % mod + 3 *
                    seg[rt].sum2 % mod * c % mod + 3 * seg[rt].sum1 * c % mod * c % mod ) % mod; 
    seg[rt].sum2 = (seg[rt].sum2 + 2 * seg[rt].sum1 * c % mod + len * c % mod * c % mod) % mod;
    seg[rt].sum1 = (seg[rt].sum1 + len * c % mod) % mod;
    seg[rt].lazy = (seg[rt].lazy + c) % mod;
}

void pushdown (int rt) {
    if (seg[rt].lazy) {  
        check (rt << 1, seg[rt].lazy);
        check (rt << 1 | 1, seg[rt].lazy);
        seg[rt].lazy = 0;
    }
}

void update (int l, int r, i64 c, int rt) {
    if (l <= seg[rt].l && r >= seg[rt].r) {
        check (rt, c);
        return ;
    }
    pushdown (rt);
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (l <= mid) update (l, r, c, rt << 1);
    if (r > mid) update (l, r, c, rt << 1 | 1);
    pushup (rt); 
}

i64 query (int l, int r, int rt) {
    if (l <= seg[rt].l && r >= seg[rt].r) {
        return seg[rt].sum3;
    }
    i64 res = 0;
    pushdown (rt);
    int mid = (seg[rt].l + seg[rt].r) >> 1;
    if (l <= mid) res = (res + query (l, r, rt << 1)) % mod;
    if (r > mid) res = (res + query (l, r, rt << 1 | 1)) % mod;
    return res;
}

i64 add (i64 c) {
    if (c < 0) {
        c += mod;
    }
    return c % mod;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    build (1, n, 1);
    while (m--) {
        int op, l, r, c;
        cin >> op >> l >> r;
        if (op == 1) {
            cin >> c;
            update (l, r, c, 1);
        } else {
            cout << add(query (l, r, 1)) << '\n';
        }
    }
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}