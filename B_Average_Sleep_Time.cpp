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
    ll n, k;
    cin >> n >> k;
    vector<ll> v(n, 0);
    for (ll i = 0; i < n; i++)
        cin >> v[i];
    ll sum = 0;
    ll i = 0, j = 0, ans = 0;
    while (j < n)
    {
        sum += v[j];
        if (j - i + 1 == k)
        {
            // slide window
            ans += sum;
            sum -= v[i];
            i++;
        }
        j++;
    }
    double d = (double)ans / (n - k + 1);
    cout << fixed << setprecision(10) << d << '\n';
    return 0;
}