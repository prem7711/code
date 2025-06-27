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
        ll n, q;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        cin >> q;
        vector<pair<ll, ll>> query(q);
        for (ll i = 0; i < q; i++)
        {
            ll x, y;
            cin >> x >> y;
            query[i] = {x, y};
        }
        vector<ll> ans(n, -1);
        for (ll i = n - 2; i >= 0; i--)
        {
            if (v[i] != v[i + 1])
                ans[i] = i + 1;
            else
                ans[i] = ans[i + 1];
        }

        for (ll i = 0; i < q; i++)
        {

            ll a = query[i].first, b = query[i].second;
            ll x = ans[a - 1];
            if (x != -1 && x < b)
                cout << a << " " << x + 1 << endl;
            else
                cout << "-1" << " " << "-1" << endl;
        }
    }
    return 0;
}
