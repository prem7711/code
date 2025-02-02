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

    vector<ll> v;
    v.push_back(0);
    for (ll a = 3; a <= 1e5; a++)
    {
        ll a1 = a * a;
        ll b = a1 / 2;
        ll c = b + 1;
        if (b * b + a * a == c * c && a1 == b + c)
            v.push_back(c);
    }
    ll t;
    cin >> t;
    while (t--)
    {

        ll n;
        cin >> n;
        int ans = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << ans - 1 << endl;
    }
    return 0;
}
