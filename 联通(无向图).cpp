#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
    
constexpr int N = 1e5 + 5;
bitset <N> vis;
vector <vector<int>> adj(N);
int n, m;

void dfs (int from) {
    vis[from] = 1;
    for (int to : adj[from]) {
        if (!vis[to]) dfs(to);
    }
}

void solve() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int from, to;
        cin >> from >> to;
        adj[from].emplace_back(to);
        adj[to].emplace_back(from); // 无向图
    } 
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) { 
            cnt++;
            dfs(i);
        }
    }
    cout << cnt << '\n';
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