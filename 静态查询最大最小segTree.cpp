//https://github.com/Ckeyliuhi/acm-iters
#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5;
struct SegTree {
    int mx, mi;
} seg[N << 2];
int a[N];

void pushup (int rt) {
    seg[rt].mx = max(seg[rt << 1].mx, seg[rt << 1 | 1].mx);
    seg[rt].mi = min(seg[rt << 1].mi, seg[rt << 1 | 1].mi);
}

void build (int l, int r, int rt) {
    if (l == r) {
        seg[rt].mx = seg[rt].mi = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build (l, mid, rt << 1);
    build (mid + 1, r, rt << 1 | 1);
    pushup (rt);
}

pair <int, int> query (int l, int r, int L, int R, int rt) {
    if (L <= l && r <= R) {
        return {seg[rt].mx, seg[rt].mi};
    }
    int mid = (l + r) >> 1;
    pair <int, int> res1, res2;
    if (L <= mid) res1 = query (l, mid, L, R, rt << 1);
    if (R > mid) res2 = query (mid + 1, r, L, R, rt << 1 | 1);
    return {max(res1.first, res2.first), min(res1.second, res2.second)};
} 
void solve() {
    
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