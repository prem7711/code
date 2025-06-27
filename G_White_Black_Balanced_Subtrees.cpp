// header files and namespaces
#include <bits/stdc++.h>
using namespace std;

// code shortcuts
typedef long long ll;
typedef vector<int> vi;
typedef pair<ll, ll> pi;
#define f first
#define s second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout << x << '\n'
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll mod = 1000000007;

ll cnt = 0;

pair<ll, ll> dfs(ll node, ll par, string &str, unordered_map<ll, vector<ll>> &ump, vector<pair<ll, ll>> &ans) {
    ll white = 0, black = 0;

    if (str[node - 1] == 'W') white++;
    else black++;

    for (auto &nb : ump[node]) {
        if (nb != par) {
            auto child = dfs(nb, node, str, ump, ans);
            white += child.first;
            black += child.second;
        }
    }

    ans[node] = {white, black};
    if (white == black) cnt++;
    return ans[node];
}

int main() {
    fast;
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        unordered_map<ll, vector<ll>> ump;
        vector<ll> v(n + 1);
        for (ll i = 2; i <= n; i++) {
            cin >> v[i];
            ump[i].PB(v[i]);
            ump[v[i]].PB(i);
        }

        string str;
        cin >> str;

        vector<pair<ll, ll>> ans(n + 1, {0, 0});
        cnt = 0;
        dfs(1, -1, str, ump, ans);
        cout << cnt << "\n";
    }
    return 0;
}
