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
void solve(unordered_map<int, int> &u, vector<int> &v)
{
    int n = v.size();
    int ct = 1;
    REP(i, 1, n - 1)
    {
        if (v[i] == v[i - 1])
        {
            ct++;
        }
        else
        {
            u[v[i - 1]] = max(u[v[i - 1]], max(ct, 1));
            ct = 1;
        }
    }
    u[v[n - 1]] = max(u[v[n - 1]], ct);
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
        vi v1(n), v2(n);
        unordered_map<int, int> u1, u2;
        REP(i, 0, n - 1)
        {
            cin >> v1[i];
        }
        REP(i, 0, n - 1)
        {
            cin >> v2[i];
        }
        solve(u1, v1);
        solve(u2, v2);
        int ans = 0;
        REP(i, 0, n - 1)
        {
            ans = max(u1[v1[i]] + u2[v1[i]], ans);
            ans = max(u1[v2[i]] + u2[v2[i]], ans);
        }

        cout << ans << endl;
    }
    return 0;
}
