#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5;
int tree[N], n;
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