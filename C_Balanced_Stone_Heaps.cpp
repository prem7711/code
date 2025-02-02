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
bool valid(int m, vector<int> &v1)
{
    int n = v1.size();
    vector<int> v = v1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (v[i] < m)
            return false;
        int ext = v[i] - m;
        ext = min(ext / 3, v1[i] / 3);
        // v[i] -= 3 * ext;
        if (i > 1)
            v[i - 1] += ext;
        if (i > 1)
            v[i - 2] += (2 * ext);
    }
    return true;
}
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
        for (int i = 0; i < n; i++)
            cin >> v[i];
        int l = 1, r = 1e9, ans = 0;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(m, v))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
