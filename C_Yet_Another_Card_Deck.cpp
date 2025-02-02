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
  int n, q;
  cin >> n >> q;
  vi v(n), query(q), ans;
  REP(i, 0, n - 1)
  {
    cin >> v[i];
  }
  REP(i, 0, q - 1)
  {
    cin >> query[i];
  }
  vi col(51, -1);
  for (int i = 0; i < n; i++)
  {
    int val = v[i];
    if (col[val] == -1)
    {
      col[val] = i;
    }
  }
  vector<pair<int, int>> t;
  for (int i = 0; i <= 50; i++)
  {
    if (col[i] != -1)
    {
      t.push_back({col[i], i});
    }
  }
  for (int i = 0; i < q; i++)
  {
    int pos = -1;
    for (int j = 0; j < t.size(); j++)
    {
      if (t[j].second == query[i])
      {
        pos = j;
      }
    }
    ans.push_back(pos + 1);
    int val1 = t[0].first;
    int val2 = t[0].second;
    t[0].first = t[pos].first;
    t[0].second = t[pos].second;
    for (int j = 1; j <= pos; j++)
    {
      int cur1 = t[j].first;
      int cur2 = t[j].second;
      t[j].first = val1;
      t[j].second = val2;
      val1 = cur1;
      val2 = cur2;
    }
  }
  for (int i = 0; i < ans.size(); i++)
  {
    cout << ans[i] << " ";
  }
  return 0;
}
