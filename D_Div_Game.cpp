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
    ll n;
    cin >> n;
    ll ans = 0;

    for (ll i = 2; i * i <= n; i++)
    {
        ll ct = 0;
        while (n % i == 0)
        {
            n = n / i;
            ct++;
        }
        ll c = 0;
        while ((c * (c + 1)) / 2 <= ct)
        {
            c++;
        }
        ans = ans + c - 1;
    }

    // If n is a prime number greater than 1, it needs to be considered as well.
    if (n > 1)
    {

        ans += 1;
    }

    print(ans);
    return 0;
}
