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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        unordered_map<ll, ll> mp;
        ll ans = 0;
        // min value=1+2=3
        // max value=n+n-1=2n-1
        for (ll i = 0; i < n; i++)
        {
            mp[v[i]] = i + 1;
        }
        for (ll i = 3; i <= 2 * n - 1; i++)
        {
            // finding factor
            for (ll j = 1; j < sqrt(i); j++)
            {
                if (i % j == 0)
                {
                    ll a = j;
                    ll b = i / j;
                    if (a != b)
                    {
                        ll x = -1e7;
                        ll y = -1e7;
                        if (mp.find(a) != mp.end())
                        {
                            x = mp[a];
                        }
                        if (mp.find(b) != mp.end())
                        {
                            y = mp[b];
                        }
                        if (x + y == i)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
