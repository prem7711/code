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
        ll n, m;
        cin >> n >> m;
        vector<vector<ll>> v(n, vector<ll>(m)), v2(m, vector<ll>(n));
        vector<vector<ll>> prefix(m, vector<ll>(n)), suffix(m, vector<ll>(n));
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> v[i][j];
            }
        }

        // Transpose the matrix
        ll sum = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                v2[j][i] = v[i][j];
            }
        }
        for (auto &row : v2)
        {
            sort(row.begin(), row.end());
        }

        for (ll i = 0; i < m; i++)
        {
            // Prefix sums
            prefix[i][0] = v2[i][0];
            for (ll j = 1; j < n; j++)
            {
                prefix[i][j] = prefix[i][j - 1] + v2[i][j];
            }

            // Suffix sums
            suffix[i][n - 1] = v2[i][n - 1];
            for (ll j = n - 2; j >= 0; j--)
            {
                suffix[i][j] = suffix[i][j + 1] + v2[i][j];
            }
        }

        for (ll i = 0; i < m; i++)
        {
            for (ll j = 0; j < n - 1; j++)
            {
                ll c2 = suffix[i][j + 1];
                sum = sum + (c2 - v2[i][j] * (n - 1 - j));
            }
        }
        cout << sum << endl;
    }
    return 0;
}
