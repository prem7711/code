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
ll w = 0, r = 0;
void helper(ll node, unordered_map<ll, vector<ll>> &ump, ll par, ll c)
{
    if (c == 0)
        w++;
    else
        r++;

    for (auto &nb : ump[node])
    {
        if (nb != par)
        {
            helper(nb, ump, node, 1 - c);
        }
    }
}
int main()
{
    fast;
    ll n;
    cin >> n;
    unordered_map<ll, vector<ll>> ump;
    for (ll i = 0; i < n - 1; i++)
    {
        ll a, b;
        cin >> a >> b;
        ump[a].push_back(b);
        ump[b].push_back(a);
    }
    helper(1, ump, 0, 0);

    ll ans = (w * r);
    n--;
    ans = ans - n;
    cout << ans << endl;

    return 0;
}
