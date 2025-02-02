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

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    if (a.second != b.second)
    {
        return a.second < b.second;
    }
    return a.first < b.first;
}
int main()
{
    fast;
    ll n, k;
    cin >> n >> k;
    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end(), cmp);
    multiset<ll> pq;

    for (int i = 0; i < k; i++)
    {
        pq.insert(-1);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        auto it = pq.upper_bound(v[i].first);
        if (it != pq.begin())
        {
            pq.erase(--it);
            pq.insert(v[i].second);
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
