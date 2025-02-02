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
int helper(int l, int r)
{
    cout << "?"
         << " " << l << " " << r << endl;
    int a;
    cin >> a;
    return r - l + 1 - a;
}
int main()
{
    fast;
    int n, t, k;
    cin >> n >> t;
    cin >> k;
    int ans = n;
    int l = 1, r = n, answer = n;
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        int z = helper(1, m);
        if (z == k)
        {
            ans = m;
        }
        if (z >= k)
        {
            r = m - 1;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << "!"
         << " " << ans << endl;
    return 0;
}
