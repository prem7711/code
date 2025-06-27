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
            cin >> v[i];
        map<ll, ll> ump;
        for (ll i = 0; i < n; i++)
        {

            ll k = v[i];
            for (ll j = 2; j * j <= k; j++)
            {
                if (k % j == 0)
                {
                    while (k % j == 0)
                    {
                        k = k / j;
                        ump[j]++;
                    }
                }
            }
            if (k != 1)
                ump[k]++;
        }
        bool ans = true;
        for (auto i : ump)
        {
            //cout<<i.first<<" "<<i.second<<" ";
            if (i.second % n != 0)
            {
                ans = false;
                break;
            }
        }

        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
