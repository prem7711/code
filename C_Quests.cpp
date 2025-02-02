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
        vi v1(n), v2(n);
        REP(i, 0, n - 1)
        {
            cin >> v1[i];
        }
        REP(i, 0, n - 1)
        {
            cin >> v2[i];
        }
        int maxi = 0, sum = 0, cc = 0;
        ;
        for (int i = 0; i < n; i++)
        {
            sum += v1[i];
            cc = max(cc, v2[i]);
            if (i < k)
            {
                maxi = max(maxi, sum + (k - i - 1) * cc);
            }
        }
        cout << maxi << endl;
    }
    return 0;
}
