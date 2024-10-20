#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using ull = unsigned long long;
 
struct mint { 
    static const int P = 998244353; 
    i64 val; 
    mint(i64 v = 0) {
        val = v % P;
        if (val < 0) val += P;
    } 
    mint operator+(const mint& b) const {
        mint res;
        res.val = val + b.val;
        if (res.val >= P) res.val -= P;
        return res;
    } 
    mint operator-(const mint& b) const {
        mint res;
        res.val = val - b.val;
        if (res.val < 0) res.val += P;
        return res;
    } 
    mint operator*(const mint& b) const {
        mint res;
        res.val = (val * b.val) % P;
        return res;
    } 
    mint power(i64 b) const {
        mint res(1);
        mint a(val);
        while(b > 0){
            if(b & 1) res = res * a;
            a = a * a;
            b >>= 1;
        }
        return res;
    } 
    mint inv() const { 
        return power(P - 2);
    } 
    mint operator/(const mint& b) const {
        return (*this) * b.inv();
    } 
    mint& operator+=(const mint& b) { return *this = *this + b; }
    mint& operator-=(const mint& b) { return *this = *this - b; }
    mint& operator*=(const mint& b) { return *this = *this * b; }
    mint& operator/=(const mint& b) { return *this = *this / b; } 
    bool operator==(const mint& b) const { return val == b.val; }
    bool operator!=(const mint& b) const { return val != b.val; } 
    friend ostream& operator<<(ostream& os, const mint& a) {
        os << a.val;
        return os;
    } 
    friend istream& operator>>(istream& is, mint& a) {
        i64 v;
        is >> v;
        a = mint(v);
        return is;
    }
};
 
void solve() { 

}

int main() { 
    cin.tie(0) -> sync_with_stdio(false); 
    int t = 1;
    cin >> t;  
    while (t--) {
        solve(); 
    }
    return 0;
}
