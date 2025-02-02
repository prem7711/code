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
        vi v(1001, -1);

        REP(i, 0, n - 1)
        {
            int c;
            cin >> c;
            v[c] = i + 1;
        }
        int ans = -1;
        for (int i = 1; i <= 1001; i++)
        {
            if (i == 1)
            {
                if (v[i] != -1)
                {
                    ans = max(ans, 2 * v[i]);
                }
            }
            else
            {
                if (v[i] != -1)
                {
                    for (int j = i + 1; j <= 1001; j++)
                    {
                        if (v[j] != -1)
                        {
                            int g = __gcd(i, j);
                            if (g == 1)
                            {
                                ans = max(ans, v[i] + v[j]);
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
