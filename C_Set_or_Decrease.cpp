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

bool valid(ll m, vector<ll> &pre, vector<ll> &v, ll k)
{
    ll n = v.size();
    if (pre.back() - m <= k)
        return true;

    for (ll i = n - 1; i >= max(1ll, n - m); i--)
    {
        ll cur_sum = pre[i - 1] - pre[0];
        ll rem = m - (n - i);
        ll cur = v[0] - rem;
        cur = cur * (n - i + 1);
        if (cur_sum + cur <= k)
            return true;
    }
    return false;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, a;
        cin >> n >> a;
        vector<ll> v(n), pre(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        pre[0] = v[0];
        for (ll i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] + v[i];
        }
        ll l = 0, r = 1e11, ans;
        while (l <= r)
        {
            ll m = l + (r - l) / 2;
            if (valid(m, pre, v, a))
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
