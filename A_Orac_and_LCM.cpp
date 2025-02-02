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

void helper(ll N, vector<ll> &spf)
{
  for (ll i = 2; i < N; i++)
  {
    spf[i] = i;
  }

  for (ll i = 2; i < N; i++)
  {
    if (spf[i] == i)
    {
      for (ll j = i * 2; j < N; j += i)
      {
        spf[j] = min(i, spf[j]);
      }
    }
  }
}

// code
int main()
{
  fast;
  ll n;
  cin >> n;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++)
  {
    cin >> v[i];
  }
  ll N = 2e5 + 1;
  vector<ll> spf(N, 1ll);
  helper(N, spf);

  vector<ll> v1[N];

  for (ll i = 0; i < n; i++)
  {
    while (v[i] != 1)
    {
      ll a = spf[v[i]];
      ll ct = 0;
      while (v[i] % a == 0)
      {
        ct++;
        v[i] /= a;
      }
      v1[a].push_back(ct);
    }
  }

  ll ans = 1;
  for (ll i = 1; i < N; i++)
  {
    if (v1[i].size() == n)
    {
      sort(v1[i].begin(), v1[i].end());
      ans = ans * pow(i, v1[i][1]);
    }
    if (v1[i].size() == n - 1)
    {
      sort(v1[i].begin(), v1[i].end());

      ans = ans * pow(i, v1[i][0]);
    }
  }

  cout << ans << endl;

  return 0;
}


ve