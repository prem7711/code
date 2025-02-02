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

bool valid(ll m, string str, ll n, ll x, ll y, vector<pair<ll, ll>> &v,ll a,ll b)
{
  // i need to find how long it can go in m days
  if (m >= n)
  {
    ll f = m / n;
    ll r = m % n;
    ll x1 = (v[n - 1].first) * f + a;
    ll y1 = (v[n - 1].second) * f +b;
    if (r != 0)
    {
      x1 += v[r - 1].first;
      y1 += v[r - 1].second;
    }
      ll d = abs(x - x1) + abs(y - y1);
      if (d <= m)
        return true;
    }
  else
  {
    ll x1=a, y1=b;
    x1 += v[m - 1].first;
    y1 += v[m - 1].second;
    ll d = abs(x - x1) + abs(y - y1);
    if (d <= m)
      return true;
  }
  return false;
}
int main()
{
  fast;
  ll a, b, c, d;
  cin >> a >> b;
  cin >> c >> d;
  ll n;
  cin>>n;
  string str;
  cin >> str;
  ll l = 0, r = 1e15, ans = -1;
  vector<pair<ll, ll>> v(n);
  pair<ll, ll> p = {0,0};
  for (ll i = 0; i < n; i++)
  {
    if (str[i] == 'U')
    {
      p.second++;
    }
    else if (str[i] == 'D')
    {
      p.second--;
    }
    else if (str[i] == 'L')
    {
      p.first--;
    }
    else
    {
      p.first++;
    }
    v[i] = p;
  }

  while (l <= r)
  {
    ll m = l + (r - l) / 2;
    if (valid(m, str, n, c, d, v,a,b))
    {
      ans = m;
      r = m - 1;
    }
    else
    {
      l = m + 1;
    }
  }
  cout << ans << endl;

  return 0;
}
