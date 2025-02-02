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
bool isvalid(long long mid, vector<long long> &v1, vector<long long> &v2, long long n, long long m)
{
    for (long long i = 0; i < n; i++)
    {
        long long cur = v1[i];
        // check whether it is covered by network or not;
        long long r = cur + mid;
        long long l = cur - mid;
        // check whether there is a network in l to r
        auto lower = lower_bound(v2.begin(), v2.end(), l);
        long long upper = lower_bound(v2.begin(), v2.end(), r) - v2.begin();
        if ((lower != v2.end() && *lower <= r) || (upper != m && v2[upper] == r))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    fast;
    ll n, m;
    cin >> n >> m;
    vector<long long> v1(n), v2(m);
    for (long long i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    for (long long i = 0; i < m; i++)
    {
        cin >> v2[i];
    }
    long long l = 0, r = 1e14, ans = 0;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (isvalid(mid, v1, v2, n, m))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}
