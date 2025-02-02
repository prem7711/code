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

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        long long n, m, q;
        cin >> n >> m >> q;
        vector<long long> v(m);
        for (ll i = 0; i < m; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        vector<ll> v2(q);
        for (ll i = 0; i < q; i++)
            cin >> v2[i];
        for (ll i = 0; i < q; i++)
        {
            long long x = v2[i];
            auto idx = lower_bound(v.begin(), v.end(), x);

            ll just_smaller = INT_MAX, just_greater = INT_MAX;
            if (idx != v.begin())
            {
                just_smaller = *(idx - 1);
            }
            if (idx != v.end())
            {
                just_greater = *idx;
            }

            ll ans = INT_MAX;
            if (just_smaller != INT_MAX && just_greater != INT_MAX)
            {
                int mid = (just_smaller + just_greater) / 2;
                ans = min(mid - just_smaller, just_greater - mid);
            }
            else if (just_smaller != INT_MAX)
            {
                ans = n - just_smaller;
            }
            else if (just_greater != INT_MAX)
            {
                ans = just_greater - 1;
            }

            print(ans);
        }
    }
    return 0;
}
