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
        ll n, c, d;
        cin >> n >> c >> d;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];

        ll ct = 0;
        map<int, int> mp;
        for (auto i : v)
        {
            mp[i]++;
        }
        vector<ll> v1(n + 1, 0);
        for (auto i : v)
        {
            if (i <= n)
                v1[i] = 1;
        }
        v1[0] = 0;

        vector<ll>pre(n+1)

        for (auto i : v1)
        {
            if (i == 1)
                ct++;
        }
        ll req = (n - ct) * d;
        ll ext = (n - ct) * c;
        cout << req + ext << endl;
    }
    return 0;
}
