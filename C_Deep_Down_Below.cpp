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

bool possible(ll m, vector<vector<ll>> &v)
{
    for (ll i = 0; i < v.size(); i++)
    {
        for (ll j = 0; j < v[i].size(); j++)
        {
            if (m <= v[i][j])
                return false;
            else
            {
                m++;
            }
        }
    }
    return true;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<vector<ll>> v(n);
        vector<ll> res;

        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            vector<ll> temp(x);
            for (ll i = 0; i < x; i++)
            {
                cin >> temp[i];
                // res.push_back(temp[i]);
            }

            v[i] = temp;
        }
        sort(v.begin(), v.end(), [](const vector<ll> &a, const vector<ll> &b)
             {
    ll maxA = 0, maxB = 0;
    for (ll i = 0; i < a.size(); i++) maxA = max(maxA, a[i] - i);
    for (ll i = 0; i < b.size(); i++) maxB = max(maxB, b[i] - i);
    return maxA < maxB; });

        ll a = 1, b = 1e10;
        ll ans = 1e10;

        while (a <= b)
        {

            ll mid = a + (b - a) / 2;

            if (possible(mid, v))
            {
                ans = mid;
                b = mid - 1;
            }
            else
            {
                a = mid + 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
