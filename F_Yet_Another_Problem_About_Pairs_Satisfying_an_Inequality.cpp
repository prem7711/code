#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n + 1);
        for (ll i = 1; i <= n; i++)
            cin >> a[i];

        multiset<ll> validIndices;
        ll ans = 0;

        for (ll j = 1; j <= n; j++)
        {
            if (a[j] < j)
            {
                // Count i in validIndices where i < a[j]
                ans += distance(validIndices.begin(), validIndices.upper_bound(a[j] - 1));
                validIndices.insert(j);
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
