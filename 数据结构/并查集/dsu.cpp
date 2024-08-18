#include <bits/stdc++.h>

using namespace std;

struct DSU {
    vector <int> f, sz;
    DSU (int n) : f(n), sz(n, 1) {
        iota(f.begin(), f.end(), 0);
    }
    int find (int x) {
        return f[x] == x ? x : f[x] = find(f[x]);
    }
    bool merge (int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false;
        sz[x] += sz[y];
        f[y] = f[x];
        return true;
    }
    bool same (int x, int y) {
        return find(x) == find(y);
    }
    int getsz (int x) {
        return sz[find(x)];
    }
} ;
/*
0 ~ n
*/

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
