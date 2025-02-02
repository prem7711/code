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
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<long long> v(n);
        map<ll, ll> ump;
        REP(i, 0, n - 1)
        {
            cin >> v[i];
            ump[v[i]]++;
        }
        string str = "NO";
        for (int i = 0; i < n; i++)
        {
            if (ump.find(v[i] + k) != ump.end())
            {
                str = "YES";
                break;
            }
        }
        cout << str << endl;
    }
    return 0;
}
