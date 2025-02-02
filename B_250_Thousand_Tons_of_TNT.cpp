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

ll helper(long long k, vector<ll> &v)
{
    ll maxi = -1e18, mini = 1e18;
    ll i = 0, ct = 0, sum = 0;
    while (i < v.size())
    {
        sum += v[i];
        ct++;
        if (ct == k)
        {
            maxi = max(maxi, sum);
            mini = min(mini, sum);
            sum = 0;
            ct = 0;
        }
        i++;
    }
    return maxi - mini;
}

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
        {
            cin >> v[i];
        }
        vector<ll> f;
        for (ll i = 1; i <= sqrt(n); i++)
        {
            if (n % i == 0)
            {
                f.push_back(i);
                if (n / i != n)
                {
                    f.push_back(n / i);
                }
            }
        }
        ll ans = 0;
        for (ll i = 0; i < f.size(); i++)
        {
            ans = max(ans, helper(f[i], v));
        }
        cout << ans << endl;
    }
    return 0;
}
