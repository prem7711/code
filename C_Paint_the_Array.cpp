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
bool isvalid(ll g, vector<ll> &v, long long idx, long long n)
{
    while (idx < n)
    {
        if (v[idx] % g == 0)
            return false;
        idx = idx + 2;
    }
    return true;
}
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
        long long g1 = v[0], i = 2;
        while (i < n)
        {
            g1 = __gcd(g1, v[i]);
            i = i + 2;
        }
        long long g2 = v[1];
        i = 3;
        while (i < n)
        {
            g2 = __gcd(g2, v[i]);
            i = i + 2;
        }
        bool a = false, b = false;
        a = isvalid(g1, v, 1, n);
        b = isvalid(g2, v, 0, n);
        // cout<<g1<<" "<<g2<<"  ";
        long long ans = 0;
        if (a)
        {
            ans = g1;
        }
        if (b)
        {
            ans = g2;
        }
        cout << ans << endl;
    }
    return 0;
}
