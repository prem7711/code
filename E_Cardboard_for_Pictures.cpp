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
long long findSquareRoot(long long n)
{
    if (n == 0 || n == 1)
        return n;

    long long start = 1, end = n, ans;

    // Binary search to find the square root
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;

        // If mid*mid is equal to n, then mid is the answer
        if (mid * mid == n)
            return mid;

        // If mid*mid is less than n, update start
        if (mid * mid < n)
        {
            start = mid + 1;
        }
        // If mid*mid is greater than n, update end
        else
            end = mid - 1;
    }
    return ans;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, c, ans = 0;
        cin >> n >> c;
        vector<ll> v(n);
        ll a = 0, b = 0;
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
            a += v[i];
            b = b + v[i] * 1ll * v[i];
        }
        a = a / n;
        ll k = c - b;
        k = k / (n * 1ll * 4);
        ll d = a * a + 4 * k;
        d = sqrt(d);
        d = d - a;
        d = d / 2;
        cout << d << endl;
    }
    return 0;
}
