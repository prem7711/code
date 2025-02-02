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
bool isvalid(long long m, vector<long long> &v, long long n, long long c)
{
    long long a = v[0], cur = 1;
    for (long long i = 1; i < n; i++)
    {
        if (v[i] - a >= m)
        {
            cur++;
            a = v[i];
        }
    }
    if (cur >= c)
        return true;

    return false;
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        long long n, c;
        cin >> n >> c;
        vector<long long> v(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long l = 1, r = 1e9, ans = 0;
        while (l <= r)
        {
            long long m = l + (r - l) / 2;
            if (isvalid(m, v, n, c))
            {
                ans = m;
                // cout<<ans<<"  ";
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
