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
        ll n;
        cin >> n;
        ll a = pow(2, n);
        ll b = 0;
        ll x = n / 2, y = n / 2;
        x--;
        ll i = 1;
        while (x > 0)
        {
            a = a + pow(2, i);
            i++;
            x--;
        }
        while (y > 0)
        {
            b = b + pow(2, i);
            i++;
            y--;
        }
        // cout << a << " " << b << "  ";
        cout << abs(a - b) << endl;
    }
    return 0;
}
