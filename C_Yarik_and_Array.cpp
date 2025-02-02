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
        vi v(n);
        REP(i, 0, n - 1)
        {
            cin >> v[i];
        }
        int ans = v[0], cur = v[0];
        for (int i = 1; i < n; i++)
        {
            int a = (abs(v[i]) + abs(v[i - 1])) % 2;

            if (a == 1)
            {
                if (cur < 0)
                    cur = 0;
                cur += v[i];
                ans = max(ans, cur);
                // cout<<cur<<"a"<<i<<"   ";
            }
            else
            {
                cur = v[i];
                ans = max(ans, cur);
            }
        }
        if (ans <= 0)
        {
            for (int i = 0; i < n; i++)
                ans = max(ans, v[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
