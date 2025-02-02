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
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> v(n);
    unordered_map<ll, ll> ump2;
    for (ll i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    // gcd of selected k numbers % m==0
    for (auto i : v)
    {
        ump2[i % m]++;
    }
    bool ans = false;
    ll rem;
    for (auto i : ump2)
    {
        if (i.second >= k)
        {
            ans = true;
            rem = i.first;
            break;
        }
    }
    vector<ll> t;
    for (auto i : v)
    {
        if (i % m == rem && k > 0)
        {
            t.push_back(i);
            k--;
        }
    }
    if (ans)
    {
        cout << "Yes" << endl;
        for (auto i : t)
            cout << i << " ";
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
