#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++) cin >> a[i];

        multiset<ll> validIndices;
        ll ans = 0;

        for (ll j = 1; j <= n; j++) {
            if (a[j] < j) {
                // Count i in validIndices where i < a[j]
                ans += distance(validIndices.begin(), validIndices.upper_bound(a[j] - 1));
                validIndices.insert(j);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}



3
5
15 14 17 42 34
3
1 7
2 15
4 5
5
7 5 3 1 7
4
1 7
5 7
2 3
2 2
7
19 20 15 12 21 7 11


2 -1 5
1 5 2 2
2 6 -1 5