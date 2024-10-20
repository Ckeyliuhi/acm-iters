#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e6 + 5;
int tree[N];
int lowbit (int x) {
    return x & -x;
}

void add (int x, int c) {
    for (int i = x; i < N; i += lowbit(i)) {
        tree[i] += c;
    }
}

int query (int x) {
    int res = 0;
    for (int i = x; i > 0; i -= lowbit(i)) {
        res += tree[i];
    }
    return res;
}

int queryS (int l, int r) {
    return query(r) - query(l - 1);
}

int kth(int k) {
    int sum = 0, x = 0;
    for (int i = log2(N); ~i; i--) {
        x += (1 << i);
        if (x >= N || sum + tree[x] >= k) {
            x -= (1 << i);
        } else {
            sum += tree[x];
        } 
    } 
    return x + 1; 
}

void solve() {  
    int n, q;
    cin >> n >> q;
    vector <array<int, 2>> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    vector <array<int, 4>> Q(q + 1);
    for (int i = 1; i <= q; i++) {
        cin >> Q[i][0] >> Q[i][1] >> Q[i][2];
        Q[i][3] = i;
    }
    sort(a.begin() + 1, a.end(), [&](auto x, auto y) {
        return x[0] > y[0];
    });
    sort(Q.begin() + 1, Q.end(), [&] (auto x, auto y) {
        return x[2] > y[2];
    }) ;
    int idx = 1;
    vector <int> ans(q + 1);
    for (int i = 1; i <= q; i++) {
        // while (a[idx][0] >= Q[i][2] && idx <= n) {
        //     add(a[idx][1], 1);
        //     idx++;
        // }
        while (a[idx][0] <= Q[i][2] && idx <= n) {
            add(a[idx][1], 1);
            idx++;
        }
        ans[Q[i][3]] = query(Q[i][1]) - query(Q[i][0] - 1);
    }
    for (int i = 1; i <= q; i++) {
        cout << ans[i] << '\n';
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