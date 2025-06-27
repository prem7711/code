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
        ll n, k;
        cin >> n >> k;

        if (n <= k)
        {
            cout << "1" << endl;
        }
        else
        {
            // find greteat factor of its which divides n;
            ll ans = 0;
            for (ll i = 2; i * i <= n && i <= k; i++)
            {
                if (n % i == 0)
                {
                    ans=max(ans,i);
                    if(n/i<=k)
                    ans=max(ans,n/i);
                }
            }
            if (ans == 0)
                cout << n << endl;
            else
            {
                //cout<<ans<<" ";
                ll x = n / ans;
                cout << x << endl;
            }
        }
    }
    return 0;
}
