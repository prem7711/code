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
        ll n, x, m;
        cin >> n >> x >> m;

        vector<pair<ll, ll>> v;
        for (ll i = 0; i < m; i++)
        {
            ll a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        ll l = x, r = x;

        for (auto &i : v)
        {
            ll a = i.first, b = i.second;

            // check if it collides with range

            if ((l >= a && l <= b) || (r >= a && r <= b))
            {
                l = min(l, min(a, b));
                r = max(r, max(a, b));
            }
        }
        ll ans = r - l + 1;
        cout << ans << endl;
    }
    return 0;
}
