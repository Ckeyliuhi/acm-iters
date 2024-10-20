#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5; 

struct SegTree {
    i64 sum, lazy; 
} seg[N << 2];

i64 a[N];

void pushup(int rt) {
    seg[rt].sum = seg[rt << 1].sum + seg[rt << 1 | 1].sum;
}

void build(int l, int r, int rt) {
    if (l == r) {
        seg[rt].sum = a[l];
        seg[rt].lazy = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(l, mid, rt << 1);
    build(mid + 1, r, rt << 1 | 1);
    pushup(rt);
}

void pushdown(int l, int r, int rt) {
    if (seg[rt].lazy) {
        int mid = (l + r) >> 1;
        seg[rt << 1].sum += seg[rt].lazy * (mid - l + 1);
        seg[rt << 1 | 1].sum += seg[rt].lazy * (r - mid);
        seg[rt << 1].lazy += seg[rt].lazy;
        seg[rt << 1 | 1].lazy += seg[rt].lazy;
        seg[rt].lazy = 0;
    }
}

void update(int l, int r, int L, int R, int c, int rt) {
    if (l >= L && r <= R) {
        seg[rt].sum += (r - l + 1) * c;
        seg[rt].lazy += c;
        return;
    }
    pushdown(l, r, rt);
    int mid = (l + r) >> 1;
    if (mid >= L) {
        update(l, mid, L, R, c, rt << 1);
    }
    if (mid < R) {
        update(mid + 1, r, L, R, c, rt << 1 | 1);
    }
    pushup(rt);
}

i64 query(int l, int r, int L, int R, int rt) {
    if (l >= L && r <= R) {
        return seg[rt].sum;
    }
    pushdown(l, r, rt);
    int mid = (l + r) >> 1;
    i64 ans = 0;
    if (mid >= L) {
        ans += query(l, mid, L, R, rt << 1);
    }
    if (mid < R) {
        ans += query(mid + 1, r, L, R, rt << 1 | 1);
    }
    return ans;
}

void solve() {
 
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}