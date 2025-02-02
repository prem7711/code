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

  const int n = 10000001;

  vector<int> prime(n, 1), valid(n, 0), pre(n, 0);

  // Sieve of Eratosthenes to find all primes less than n
  prime[0] = prime[1] = 0; // 0 and 1 are not primes
  for (int i = 2; i * i < n; i++)
  {
    if (prime[i] == 1)
    {
      for (int j = i * i; j < n; j += i)
      {
        prime[j] = 0;
      }
    }
  }
  for (int i = 0; i * i < n; i++)
  {
    for (int j = 0; ((j * j * j * j) + (i * i)) < n; j++)
    {
      valid[((j * j * j * j) + (i * i))] = 1;
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (valid[i] == 1 && prime[i] == 1)
    {
      pre[i] = 1;
    }
  }
  for (int i = 1; i < n; i++)
  {
    pre[i] += pre[i - 1];
  }

  int t;
  cin >> t;
  while (t--)
  {
    int k;
    cin >> k;

    cout << pre[k] << endl;
  }
  return 0;
}
