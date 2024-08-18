#include <bits/stdc++.h>

using namespace std;

namespace Prime {
    constexpr int N = 1e5 + 5;
    bool isPrime (int x) { // √x
        if (x < 2) return false;
        for (int i = 2; i <= x / i; i++) {
            if (x % i == 0) {
                return false;
            }
        }
        return true;
    }

    vector <int> getFactors (int n) { // √x 非顺序 
        vector <int> factors;
        // set <int> factors;
        for (int i = 1; i <= n / i; i++) {
            if (n % i == 0) {
                factors.push_back(i);
                if (i * i != n) {
                    factors.push_back(n / i);
                }
                // factors.insert(i);
                // factors.insert(n / i);
            }
        }
        return factors;
        // return vector <int> (factors.begin(), factors.end());
    }

    bitset <N> sieve_prime;  
    
    void sieve (int n = N) { // N log log N
        sieve_prime[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (!sieve_prime[i]) {
                for (int j = i + i; j <= n; j += i) {
                    sieve_prime[j] = 1;
                }
            }
        }   
    }

    bitset <N> eluer_prime;
    vector <int> prime;
    int pre_prime[N];
    void eluer (int n = N) { // N 
        for (int i = 2; i <= n; i++) {
            pre_prime[i] = pre_prime[i - 1];
            if (!eluer_prime[i]) {
                prime.push_back(i);
                pre_prime[i] ++;   
            } 
            for (int& p : prime) {
                if (i * p >= n) break;
                eluer_prime[i * p] = 1;
                if (i % p == 0) break;
            }
        }
    } 
} using namespace Prime;

void solve() {
    
}

int main() {
    cin.tie(0) -> sync_with_stdio(false);
    // freopen("C:/Users/26842/Desktop/acm/in.txt", "r", stdin);
    int _ = 1;  
    while (_--) {
        solve();
    }
    return 0;
}
