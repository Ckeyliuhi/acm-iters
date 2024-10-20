#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5;
i64 a[N], n, m, mod;
struct SegTree {
    i64 sum, mul, lazy;
} seg[N << 2];

void pushup (int rt) {
    seg[rt].sum = (seg[rt << 1].sum + seg[rt << 1 | 1].sum) % mod;
}

void build (int l, int r, int rt) {
    seg[rt].mul = 1;
    if (l == r) {
        seg[rt].sum = a[l] % mod;
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, rt << 1);
    build (mid + 1, r, rt << 1 | 1);
    pushup (rt);
}

void pushdown (int rt, int l, int r) { 
    int mid = (l + r) >> 1;
    int left = mid - l + 1, right = r - mid; 
    for (int child : {rt << 1, rt << 1 | 1}) {
        seg[child].sum = (seg[child].sum * seg[rt].mul + seg[rt].lazy * (child == rt << 1 ? left : right)) % mod; 
        seg[child].lazy = (seg[child].lazy * seg[rt].mul + seg[rt].lazy) % mod;
        seg[child].mul = (seg[child].mul * seg[rt].mul) % mod; 
    }
    seg[rt].lazy = 0; seg[rt].mul = 1;
}   

void updateMul (int l, int r, int L, int R, i64 c, int rt) {
    if (l >= L && r <= R) {
        seg[rt].lazy = (seg[rt].lazy * c) % mod;
        seg[rt].mul = (seg[rt].mul * c) % mod;
        seg[rt].sum = (seg[rt].sum * c) % mod;
        return ;
    }
    pushdown (rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) updateMul (l, mid, L, R, c, rt << 1);
    if (R > mid) updateMul (mid + 1, r, L, R, c, rt << 1 | 1);
    pushup (rt);
}

void updateAdd (int l, int r, int L, int R, i64 c, int rt) {
    if (l >= L && r <= R) {
        seg[rt].lazy = (seg[rt].lazy + c) % mod;
        seg[rt].sum = (seg[rt].sum + c * (r - l + 1)) % mod;
        return ;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) updateAdd(l, mid, L, R, c, rt << 1);
    if (R > mid) updateAdd(mid + 1, r, L, R, c, rt << 1 | 1);
    pushup(rt); 
}

i64 query (int l, int r, int L, int R, int rt) {
    if (l >= L && r <= R) {
        return seg[rt].sum;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    i64 res = 0;
    if (L <= mid) res = (res + query(l, mid, L, R, rt << 1)) % mod;
    if (R > mid) res = (res + query(mid + 1, r, L, R, rt << 1 | 1)) % mod;
    return res % mod;
}

void solve() {
    cin >> n >> m >> mod;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build (1, n, 1); 
    while (m--) {
        int op;
        cin >> op;
        if (op == 1) {
            int l, r, c;
            cin >> l >> r >> c;
            updateMul(1, n, l, r, c, 1);
        } else if (op == 2) {
            int l, r, c;
            cin >> l >> r >> c;
            updateAdd(1, n, l, r, c, 1);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(1, n, l, r, 1) << '\n';
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