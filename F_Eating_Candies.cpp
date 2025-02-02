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
        ll n;
        cin >> n;
        vector<long long> v(n);
        vector<long long> ans;
        long long c = 0;
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
            c += v[i];
            ans.push_back(c);
        }
        long long res = 0, sum = 0;
        for (long long i = n - 1; i >= 0; i--)
        {
            sum += v[i];
            long long idx = lower_bound(ans.begin(), ans.end(), sum) - ans.begin();
            // cout<<sum<<" "<<ans[idx]<<"  ";
            if (idx < i && ans[idx] == sum)
            {
                res = max(res, idx + 1 + n - i);
            }
        }
        cout << res << endl;
    }
    return 0;
}
