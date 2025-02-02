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
bool possible(int a, int b)
{
    for (int i = 31; i >= 0; i--)
    {
        int m = (1 << i) & a;
        int n = (1 << i) & b;
        if (m && !n)
            return false;
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
        int n, x;
        cin >> n >> x;
        vi v1(n), v2(n), v3(n);
        REP(i, 0, n - 1)
        {
            cin >> v1[i];
        }
        REP(i, 0, n - 1)
        {
            cin >> v2[i];
        }
        REP(i, 0, n - 1)
        {
            cin >> v3[i];
        }
        int a = 0;
        for (int i = 0; i < n; i++)
        {
            if (possible(v1[i], x))
            {
                a = a | v1[i];
            }
            else
            {
                break;
            }
        }
        // cout << a << " ";
        for (int i = 0; i < n; i++)
        {
            if (possible(v2[i], x))
            {
                a = a | v2[i];
            }
            else
            {
                break;
            }
            // cout << a << " "
        }
        // cout << a << " ";
        for (int i = 0; i < n; i++)
        {
            if (possible(v3[i], x))
            {
                a = a | v3[i];
            }
            else
            {
                break;
            }
        }
        // cout << a << " ";
        if (a == x)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
