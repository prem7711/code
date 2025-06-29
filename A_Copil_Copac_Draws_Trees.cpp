#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define PB push_back

ll ans;

void dfs(int node, int par, int lastEdgeIdx, vector<vector<pair<int, int>>> &adj, int depth) {
    ans = max(ans, (ll)depth);
    for (auto &[nb, edgeIdx] : adj[node]) {
        if (nb == par) continue;

        if (edgeIdx < lastEdgeIdx)
            dfs(nb, node, edgeIdx, adj, depth + 1);  // new reading
        else
            dfs(nb, node, edgeIdx, adj, depth);      // same reading
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<pair<int, int>>> adj(n + 1);

        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].PB({v, i});
            adj[v].PB({u, i});
        }

        ans = 1;
        dfs(1, -1, -1, adj, 1);  // node, parent, previous edge index, adj, reading count

        cout << ans << '\n';
    }

    return 0;
}
