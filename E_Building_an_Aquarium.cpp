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
bool isvalid(vi &v, int x, ll m)
{
    ll ans = 0;
    ll k = x;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < m)
        {

            ans = ans + m - v[i];
            //  cout<<v[i]<<" "<<m<<" "<<ans<<" ";
        }
    }

    if (ans <= k)
    {
        //   cout<<ans<<"a"<<x<<" ";
        return true;
    }

    return false;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, x;
        cin >> n >> x;
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        ll ans = 0, l = 0, r = 1e15;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (isvalid(v, x, m))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
            // cout << m << " ";
        }
        cout << ans << endl;
    }
    return 0;
}
