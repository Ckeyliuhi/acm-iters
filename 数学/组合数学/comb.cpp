#include <bits/stdc++.h>

using namespace std;


#include <bits/stdc++.h>

using namespace std;

constexpr int P = 998244353;
using i64 = long long;
// assume -P <= x < 2P
int norm(int x) {
    if (x < 0) {
        x += P;
    }
    if (x >= P) {
        x -= P;
    }
    return x;
}
template<class T> // a ^ b
T power(T a, i64 b) {
    T res = 1;
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
struct Z {
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(i64 x) : x(norm(x % P)) {}
    int val() const {
        return x;
    }
    Z operator-() const { // -x
        return Z(norm(P - x));
    }
    Z inv() const { // inv
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs) { // *
        x = i64(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs) { // +
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs) { // -
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs) { // divide
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs) { // *
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs) { // +
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs) { // -
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs) { // divide
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend std::istream &operator>>(std::istream &is, Z &a) { // inv
        i64 v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend std::ostream &operator<<(std::ostream &os, const Z &a) { // 输出流
        return os << a.val();
    }
};

struct Comb {
    int n;
    vector<Z> _fac, _inv; 
    Comb() : _fac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    void init(int m) {
        if (m <= n) return;
        _fac.resize(m + 1);
        _inv.resize(m + 1);
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _inv[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _inv[i - 1] = _inv[i] * i;
        }
        n = m;
    }
    Z fac(int x) {
        if (x > n) init(x);
        return _fac[x];
    }
    Z inv(int x) {
        if (x > n) init(x);
        return _inv[x];
    }
    Z C(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(y) * inv(x - y);
    }
    Z P(int x, int y) {
        if (x < 0 || y < 0 || x < y) return 0;
        return fac(x) * inv(x - y);
    }
} comb(int(1e5 + 5));

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
