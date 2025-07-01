// header files and namespaces
#include <bits/stdc++.h>
using namespace std;

// code shortcuts
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define f first
#define s second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout << x << '\n'
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll mod = 1000000007;

// code
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];

        vector<ll> dif;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            ll d = k - (v[i] % k);

            d %= k;

            if (d != 0)
                mp[d]++;
        }
        ll ans = 0;
        for (auto i : mp)
        {
            ll val = i.first;
            ll fre = i.second;

            ans = max(ans, (fre - 1) * k + val);
        }
        if (ans != 0)
            ans += 1;
        cout << ans << endl;
    }
    return 0;
}
