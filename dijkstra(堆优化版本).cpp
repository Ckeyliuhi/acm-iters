#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
    
constexpr int N = 1e5 + 5, inf = 1e9;
vector <vector<pair<int, int>>> adj(N); 
bitset <N> vis;
int dist[N], n, m, s;
int path[N];

void dijkstra (int s) {
    for (int i = 1; i <= n; i++) dist[i] = inf, path[i] = -1;
    priority_queue <pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while (pq.size()) {
        auto [dw, from] = pq.top();
        pq.pop();
        if (vis[from]) continue;
        vis[from] = 1;
        for (auto &[w, to] : adj[from]) {
            if (dist[from] + w < dist[to]) {
                dist[to] = dist[from] + w;
                path[to] = from;
                pq.push({dist[to], to});
            }
        }
    }
}

void Print (int from) { 
    stack <int> st;
    int cur = from;
    while (cur != -1) {
        st.push(cur); 
        if (cur == s) break; 
        cur = path[cur];
    }
    if (st.top() == s) {
        while (st.size()) {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
    return ;
} 

void solve() {
    cin >> n >> m >> s;
    for (int i = 1; i <= m; i++) {
        int from, to, w;
        cin >> from >> to >> w;
        adj[from].emplace_back(w, to);
    }
    dijkstra(s); 
    Print(s);
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