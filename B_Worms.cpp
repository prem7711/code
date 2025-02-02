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
int main()
{
    fast;
    ll t;
    ll n;
    cin >> n;
    vector<long long> v(n);
    long long a = 0, c;
    for (long long i = 0; i < n; i++)
    {
        cin >> c;
        a += c;
        v[i] = a;
    }
    long long m;
    cin >> m;
    vector<long long> v1(m);
    for (long long i = 0; i < m; i++)
    {
        cin >> v1[i];
    }
    vector<long long> ans;
    for (long long i = 0; i < m; i++)
    {
        long long idx = lower_bound(v.begin(), v.end(), v1[i]) - v.begin();
        ans.push_back(idx + 1);
    }
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}
