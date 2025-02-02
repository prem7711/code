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
#define fast                    \
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
    ll n, k, a, b;
    cin >> n >> k >> a >> b;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
      ll x, y;
      cin >> x >> y;
      v.push_back({x, y});
    }
    ll x1 = v[a - 1].first, y1 = v[a - 1].second;
    ll x2 = v[b - 1].first, y2 = v[b - 1].second;
    ll dis = 1e18;
    if (a <= k)
    {
      for (ll i = 0; i < k; i++)
      {
        ll x3 = v[i].first, y3 = v[i].second;
        dis = min(dis, abs(x3 - x2) + abs(y3 - y2));
      }
    }
    else
    {
      dis = min(dis, abs(x2 - x1) + abs(y2 - y1));
      ll m = 1e18, n = 1e18;
      for (ll i = 0; i < k; i++)
      {
        ll x3 = v[i].first, y3 = v[i].second;
        m = min(m, abs(x3 - x2) + abs(y3 - y2));
      }

      for (ll i = 0; i < k; i++)
      {
        ll x3 = v[i].first, y3 = v[i].second;
        n = min(n, abs(x3 - x1) + abs(y3 - y1));
      }
      dis = min(dis, m + n);
    }
    cout << dis << endl;
  }
  return 0;
}
