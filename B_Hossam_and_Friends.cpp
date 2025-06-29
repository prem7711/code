#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast ios::sync_with_stdio(0); cin.tie(0);

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        
        vector<ll> min_right(n + 2, n + 1); // min_right[i] = smallest y > i that is enemy with i

        for (int i = 0; i < m; ++i) {
            ll x, y;
            cin >> x >> y;
            if (x > y) swap(x, y);
            min_right[x] = min(min_right[x], y);
        }

        ll limit = n + 1;
        for (ll i = n; i >= 1; --i) {
            limit = min(limit, min_right[i]); // track the tightest limit from i onwards
            min_right[i] = limit;
        }

        ll ans = 0;
        for (ll i = 1; i <= n; ++i) {
            ans += min_right[i] - i;
        }

        cout << ans << '\n';
    }
    return 0;
}
