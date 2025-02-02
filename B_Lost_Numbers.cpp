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
  set<int> st = {4, 8, 15, 16, 23, 42};
  cout << "? "
       << "1 "
       << "2" << endl;
  int ab, ac, ad, ae;
  cin >> ab;
  cout << "? "
       << "1 "
       << "3" << endl;
  cin >> ac;
  cout << "? "
       << "1 "
       << "4" << endl;
  cin >> ad;
  cout << "? "
       << "1 "
       << "5" << endl;
  cin >> ae;
  pair<int, int> p1, p2;
  for (auto i : st)
  {
    if (ab % i == 0 && st.find(ab / i) != st.end())
    {
      p1.first = i;
      p1.second = ab / i;
    }

    if (ac % i == 0 && st.find(ac / i) != st.end())
    {
      p2.first = i;
      p2.second = ac / i;
    }
  }
  vector<int> ans(6);
  if (p1.first == p2.first || p1.first == p2.second)
    ans[0] = p1.first;
  else
    ans[0] = p1.second;

  ans[1] = ab / ans[0];
  ans[2] = ac / ans[0];
  ans[3] = ad / ans[0];
  ans[4] = ae / ans[0];
  ans[5] = (4 * 8 * 15 * 16 * 23 * 42) / (ans[0] * ans[1] * ans[2] * ans[3] * ans[4]);
  cout << "! ";
  for (auto i : ans)
    cout << i << " ";
  cout << endl;

  return 0;
}
