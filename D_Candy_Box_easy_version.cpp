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
        unordered_map<ll, ll> u;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            u[v[i]]++;
        }
        vector<ll> t;
        for (auto i : u)
        {
            t.push_back(i.second);
        }
        sort(t.begin(), t.end());
        ll ans = 0;
        ll s = t.size() - 1;
        ll maxi = t.back();
        while (s >= 0)
        {

            if (maxi == 0)
                break;
            if (t[s] >= maxi)
            {
                ans = ans + maxi;
                maxi--;
                if (maxi == 0)
                    break;
            }
            else
            {
                ans = ans + t[s];
                maxi = t[s] - 1;
                if (maxi == 0)
                    break;
            }
            s--;
        }
        cout << ans << endl;
    }
    return 0;
}
