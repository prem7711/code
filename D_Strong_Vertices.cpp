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

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.first != b.first)
        return a.first > b.first;
    else
        return a.second > b.second;
}

// code
int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin>>n;
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];
        vector<pair<ll, ll>> c;
        for (ll i = 0; i < n; i++)
        {
            c.push_back({a[i] - b[i], i});
        }
        sort(c.begin(), c.end(), cmp);
        vector<ll> ans;
        for (ll i = 0; i < n; i++)
        {
            if (i == 0)
                ans.push_back(c[i].second + 1);
            else
            {
                if (c[i].first == c[0].first)
                {
                    ans.push_back(c[i].second + 1);
                }
            }
        }
        cout << ans.size() << endl;
        sort(ans.begin(),ans.end());
        for (auto i : ans)
            cout << i <<" ";

        cout<<endl;
    }
    return 0;
}
