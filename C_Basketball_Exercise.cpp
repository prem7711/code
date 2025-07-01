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
    ll n;
    cin >> n;
    vector<ll> v1(n), v2(n);

    for (ll i = 0; i < n; i++)
        cin >> v1[i];

    for (ll i = 0; i < n; i++)
        cin >> v2[i];

    vector<pair<ll, ll>> ans(n + 1, {0, 0});
    ans[1] = {v1[0], v2[0]};
    ll c = max(v1[0], v2[0]);
    for (ll i = 1; i < n; i++)
    {

        // i want to take first element

        ans[i + 1].first = max(ans[i].first, v1[i] + max(ans[i - 1].first, max(ans[i - 1].second, ans[i].second)));

        ans[i + 1].second = max(ans[i].second, v2[i] + max(ans[i - 1].second, max(ans[i - 1].first, ans[i].first)));

        c = max(c, max(ans[i + 1].first, ans[i + 1].second));
    }

    // for (ll i = 1; i <= n; i++)
    // {
    //     cout << ans[i].first << " " << ans[i].second << endl;
    // }

    cout << c << endl;
    return 0;
}
