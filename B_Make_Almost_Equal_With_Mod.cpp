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
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        ll a = v[1] - v[0];
        ll b = a, c = a;
        if (n > 2)
        {
            b = v[2] - v[0];
            c = v[2] - v[1];
        }
        map<ll, ll> m1, m2, m3;
        for (ll i = 0; i < v.size(); i++)
        {
            ll r1 = v[i] % a;
            ll r2 = v[i] % b;
            ll r3 = v[i] % c;
            m1[r1]++;
            m2[r2]++;
            m3[r3]++;
        }
        if (m1.size() == 2)
            cout << a << endl;
        else if (m2.size() == 2)
            cout << b << endl;
        else if (m3.size() == 2)
        {
            cout << c << endl;
        }
        else
        {
            ll ans = v[n - 1] + 1;
            cout << ans << endl;
        }
    }
    return 0;
}
