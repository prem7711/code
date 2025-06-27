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

    vector<ll> vis(n + 1, 1); // used to mark if a value has been processed
    ll i = 0, j = 0, ans = 0;

    while (i < n)
    {
        if (j < n && v2[i] == v1[j])
        {
            vis[v1[j]] = 0;
            i++;
            j++;
        }
        else
        {
            while (j < n && vis[v1[j]] == 0)
                j++;

            if (j < n && v2[i] != v1[j])
            {
                ans++;
                vis[v2[i]] = 0;
            }
            else if (j < n && v2[i] == v1[j])
            {
                vis[v1[j]] = 0;
                j++;
            }

            i++;
        }
    }

    cout << ans << '\n';
    return 0;
}
