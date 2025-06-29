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

int main()
{
    fast;
    ll n;
    cin >> n;

    vector<ll> v(n);
    for (ll i = 0; i < n; i++)
        cin >> v[i];

    ll pos = 0, neg = 0;
    vector<pair<ll, ll>> t(n, {0, 0});

    for (ll i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            if (v[i] > 0)
            {
                t[i].first = 1;
            }
            else
            {
                t[i].second = 1;
            }
        }
        else
        {

            if (v[i] > 0)
            {
                t[i].first = 1 + t[i + 1].first;
                t[i].second = t[i + 1].second;
            }
            else
            {
                t[i].first = t[i + 1].second;
                ;
                t[i].second = 1 + t[i + 1].first;
            }
        }

        pos = pos + t[i].first;
        neg = neg + t[i].second;
    }
    cout << neg << " " << pos << endl;
    return 0;
}
