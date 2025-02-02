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
        ll n, q;
        cin >> n >> q;
        vector<ll> v1(n), v2(q);
        for (ll i = 0; i < n; i++)
        {
            cin >> v1[i];
        }
        for (ll i = 0; i < q; i++)
        {
            cin >> v2[i];
        }
        sort(v2.begin(), v2.end());
        reverse(v2.begin(), v2.end());
        for (ll i = 0; i < v2.size(); i++)
        {
            for (ll i = 0; i < n; i++)
            {
                if (v1[j] % (1LL << v2[i]) == 0)
                {
                    v1[j] += (1LL << (v2[i] - 1));
                }
            }
        }
        for (auto i : v1)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
