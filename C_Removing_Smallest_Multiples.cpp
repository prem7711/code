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
        int n;
        cin >> n;
        string str;
        cin >> str;
        vector<int> vis(n + 1, 0);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            // iterating over its multiple
            for (int j = i; j <= n; j += i)
            {
                if (str[j - 1] == '1')
                    break;
                if (str[j - 1] == '0')
                {
                    if (vis[j - 1] == 0)
                    {
                        vis[j - 1] = 1;
                        ans += (ll)i;
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
