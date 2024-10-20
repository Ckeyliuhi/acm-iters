#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
constexpr int N = 1e5 + 5;
int f[N], sz[N];
void init() {
    for (int i = 1; i < N; i++) {
        f[i] = i, sz[i] = 1;
    }
}

int find (int x) {
    return f[x] == x ? x : f[x] = find(f[x]);
}

void merge (int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return ;
    if (sz[x] < sz[y]) swap(x, y);
    f[y] = x; sz[x] += sz[y];
    return ;
}

bool Same (int x, int y) {
    return find(x) == find(y);
}

int Size (int x) {
    return sz[find(x)];
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