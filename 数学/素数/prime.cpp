#include <bits/stdc++.h>
 
using namespace std;
using i64 = int64_t;
    
namespace Prime { 
    constexpr int N = 1e5 + 5;
    bitset <N> sieve_prime;
    void seive (int n = N - 1) { // sieve (n log n)
        sieve_prime[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!sieve_prime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    sieve_prime[j] = 1;
                }
            }
        }
    } 
    bool is_prime (int x) { // √x
        if (x < 2) return false;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }
    vector <int> getFactor (int x) { // √x
        vector <int> factors;
        for (int i = 1; i <= x / i; i++) {
            if (x % i == 0) {
                factors.push_back(i);
                if (i != x / i) {
                    factors.push_back(x / i);
                }
            }
        }
        return factors;
    }
    bitset <N> euler_prime;
    vector <int> prime;
    int prime_cnt[N] {};
    void euler (int n = N - 1) {
        for (int i = 2; i <= n; i++) {
            prime_cnt[i] = prime_cnt[i - 1];
            if (!euler_prime[i]) {
                prime.emplace_back(i);
                prime_cnt[i]++;
            }
            for (int &p : prime) {
                if (p * i >= n) break;
                euler_prime[p * i] = 1;
                if (i % p == 0) break;
            }
        }
    }
} using namespace Prime;

void solve() {
    euler();
    for (int i : prime) {
        cout << i << ' ';
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
