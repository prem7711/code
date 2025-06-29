#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll fact[20];

void precompute() {
    fact[0] = 1;
    for (int i = 1; i <= 18; i++) {
        fact[i] = fact[i - 1] * i;
    }
}

int main() {
    fast;
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ll max_score = 1;
            int max_len = 0;
            ll prod = 1;

            for (int j = 0; j < 18 && i - j >= 0; j++) {
                if (__builtin_mul_overflow(prod, a[i - j], &prod)) break;
                ll score = prod / fact[j + 1];
                if (score > max_score) {
                    max_score = score;
                    max_len = j + 1;
                } else if (score == max_score) {
                    max_len = max(max_len, j + 1);
                }
            }

            ans[i] = max(max_len, 1);
        }

        for (auto x : ans) cout << x << " ";
        cout << '\n';
    }

    return 0;
}
