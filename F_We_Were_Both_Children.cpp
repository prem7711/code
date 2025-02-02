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
        int n;
        cin >> n;
        vector<int> v1(n + 1, 0), v2(n);
        map<int, int> u;
        for (int i = 0; i < n; i++)
        {
            cin >> v2[i];
            u[v2[i]]++;
        }
        for (auto i : u)
        {
            for (int j = i.first; j <= n; j += i.first)
            {
                v1[j] += i.second;
            }
        }
        int ans = 0;
        for (auto i : v1)
            ans = max(ans, i);
        cout << ans << endl;
    }
    return 0;
}