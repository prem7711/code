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
        ll m = 2022;
        ll n;
        cin >> n;
        ll ans;
        ll a = n, b = n + 1, c = 4 * n - 1;
        if (n % 2 == 0)
        {
            ans = ((((a * m) / 6) % mod * b) % mod * c) % mod;
        }
        else
        {
            ans = ((((b * m) / 6) % mod * a) % mod * c) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}
