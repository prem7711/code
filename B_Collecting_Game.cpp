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
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    REP(i, 0, n - 1)
    {
      long long c;
      cin >> c;
      v.push_back({c, i});
    }
    sort(v.begin(), v.end());
    vector<long long> v1(n, 0), v2(n, 0);
    // prefix array
    v1[0] = v[0].first;
    for (long long i = 1; i < n; i++)
    {
      v1[i] = v1[i - 1] + v[i].first;
    }
    for (long long i = n - 1; i >= 0; i--)
    {
      if (i == n - 1)
      {
        v2[v[i].second] = i;
      }
      else
      {
        ll val = v1[i];
        ll next = v[i + 1].first;
        if (val >= next)
        {
          v2[v[i].second] = v2[v[i + 1].second];
        }
        else
        {
          v2[v[i].second] = i;
        }
      }
    }
    // for(auto i:v1)
    // cout<<i<<" ";

    for (auto i : v2)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
