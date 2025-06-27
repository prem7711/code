#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fast;
    int t;
    cin >> t;

    const int MAXLEN = 20;
    vector<ll> fact(MAXLEN + 1);
    fact[0] = 1;
    for (int i = 1; i <= MAXLEN; i++) {
        fact[i] = fact[i - 1] * i;
    }

    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            ll prod = 1;
            ll best_len = 0;
            __int128 max_score = 1;

            for (int len = 1; len <= MAXLEN && i - len + 1 >= 0; len++) {
                if (prod > 1e18 / a[i - len + 1]) break;
                prod *= a[i - len + 1];
                __int128 score = prod;
                score *= 1; // as numerator
                score /= fact[len]; // divide by len!
                if (score > max_score) {
                    max_score = score;
                    best_len = len;
                } else if (score == max_score) {
                    best_len = max(best_len, (ll)len);
                }
            }
            res[i] = best_len;
        }

        for (int x : res) cout << x << " ";
        cout << '\n';
    }

    return 0;
}
