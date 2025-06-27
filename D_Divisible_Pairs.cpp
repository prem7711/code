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
        ll n, x, y;
        cin >> n >> x >> y;
        map<pair<ll, ll>, ll> ump;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];

        ll ans = 0;
        for (ll i = n - 1; i >= 0; i--)
        {
            ll a = (x - (v[i] % x) + x) % x;
            ll b = v[i] % y;
            if (ump.find({a, b}) != ump.end())
            {
                ans += ump[{a, b}];
            }
            ump[{v[i] % x, v[i] % y}]++;
        }

        cout << ans << endl;
    }
    return 0;
}
