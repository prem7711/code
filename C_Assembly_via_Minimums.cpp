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
        ll n1 = (n * (n - 1)) / 2;
        vector<ll> v(n1);
        for (int i = 0; i < n1; i++)
            cin >> v[i];
        sort(v.begin(), v.end());
        ll j = 0, i = n - 1;
        vector<ll> ans;
        for(auto i:v)
        cout<<i<<" ";
        cout<<endl;
        while (j <= n)
        {
            ans.push_back(v[j]);
            j += i;
            i--;
        }
        for (ll i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
    }
    return 0;
}
