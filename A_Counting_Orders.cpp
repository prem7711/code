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
    int n;
    cin >> n;
    vi v1(n), v2(n);
    REP(i, 0, n - 1)
    {
      cin >> v1[i];
    }
    REP(i, 0, n - 1)
    {
      cin >> v2[i];
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    ll taken = 0, ans = 1;
    for (ll i = n - 1; i >= 0; i--)
    {
      ll val = v2[i];
      ll idx = upper_bound(v1.begin(), v1.end(), val) - v1.begin();
      ll cur = n - idx;
      cur -= taken;
      taken++;
      ans = ((ans) % mod * (cur) % mod) % mod;
      // cout << cur << "a" << idx << "  ";
    }
    cout << ans << endl;
  }
  return 0;
}
