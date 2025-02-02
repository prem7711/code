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
    vector<long long> v(n);
    REP(i, 0, n - 1)
    {
      cin >> v[i];
    }
    long long mn = INT_MAX, sum = 0, ct1 = 0, ct2 = 0;
    bool negative = false;
    for (int i = 0; i < n; i++)
    {
      sum += abs(v[i]);
      mn = min(mn, abs(v[i]));
      if (v[i] < 0)
      {
        ct1++;
        negative = true;
      }
      if (v[i] == 0)
      {
        ct2++;
      }
    }
    if (negative && (ct1 % 2 == 1) && (ct1 + ct2) % 2 == 1)
    {
      sum -= 2 * mn;
    }
    cout << sum << endl;
  }
  return 0;
}
