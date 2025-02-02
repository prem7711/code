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
        ll n, x, y;
        cin >> n >> x >> y;
        ll lcm = (x * y) / __gcd(x, y);
        ll x1 = n / x - n / lcm;
        ll st = n - x1;
        x1 = (n * (n + 1)) / 2 - (st * (st + 1)) / 2;
        ll y1 = n / y - n / lcm;
        y1 = (y1 * (y1 + 1)) / 2;
        cout << x1 - y1 << endl;
    }
    return 0;
}
