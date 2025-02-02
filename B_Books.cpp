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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll i = 0, j = 0, t = 0, ans = 0;
    while (j < n)
    {
        t += v[j];
        if (t <= k)
        {
            ans = max(ans, j - i + 1);
        }
        else
        {
            while (t > k && i <= j)
            {
                t -= v[i];
                i++;
            }
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}
