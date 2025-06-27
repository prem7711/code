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

ll gcd(ll a, ll b)
{
    if (a <= b)
    {
        ll x = a;
        a = b;
        b = x;
    }
    if (b == 0)
        return a;
    if (a == 0)
        return b;
    return gcd(b, a % b);
}
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;

        ll ans = 1e10;
        ll p, q;

        for (ll i = 1; i * i <= n; i++)
        {
            if (n % i == 0)
            {
                ll a = i, b = n / i;
                ll c = n - a, d = n - b;

                // calculate lcm of a and c   and b and d and set it

                ll x = (a * c) / gcd(a, c), y = (b * d) / gcd(b, d);

              //cout<<a<<" "<<c<<" "<<b<<" "<<d<<"   ";

                if (x < ans)
                {
                    p = a;
                    q = c;
                    ans = x;
                }
                if (y < ans && d!=0)
                {
                    p = b;
                    q = d;
                    ans = y;
                }
            }
        }
        ll a = min(p, q), b = max(p, q);
        cout << a << " " << b << endl;
    }
    return 0;
}
