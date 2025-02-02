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
        int n, k;
        cin >> n >> k;
        vector<vector<int>> v1(n, vector<int>(n));
        vector<vector<int>> v2(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v1[i][j];
                v2[n - i - 1][n - j - 1] = v1[i][j];
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (v1[i][j] != v1[n - i - 1][n - j - 1])
                {
                    k--;
                }
            }
        }
        if (n % 2 == 1)
        {
            for (int j = 0; j < n / 2; j++)
            {
                if (v1[n / 2][j] != v1[n / 2][n - j - 1])
                {
                    k--;
                }
            }
        }
        if (k >= 0 && (k == 0 || k % 2 == 0))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
