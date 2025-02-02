#include <bits/stdc++.h>
using namespace std;

// Code shortcuts
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

// Code
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> v1(n), v2(n);
        for (ll i = 0; i < n; i++)
            cin >> v1[i];
        for (ll i = 0; i < n; i++)
            cin >> v2[i];

        ll ans = 0, i = 0, cur = 0;
        for (ll j = 0; j < n; j++)
        {
            if (j > 0 && v2[j - 1] % v2[j] != 0)
            {
                i = j;
                cur = 0;
            }
            cur += v1[j];
            while (cur > k && i <= j)
            {
                cur -= v1[i];
                i++;
            }
            ans = max(ans, j - i + 1);
        }

        if (ans == 0)
        {
            for (auto i : v1)
            {
                if (i <= k)
                    ans = 1;
            }
        }

        cout << ans << endl;
    }
    return 0;
}
