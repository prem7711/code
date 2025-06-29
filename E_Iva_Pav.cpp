#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 2e5 + 5;
const int LOG = 20;

int a[MAXN], st[MAXN][LOG], lg[MAXN];

int get_and(int l, int r) {
    int j = lg[r - l + 1];
    return st[l][j] & st[r - (1 << j) + 1][j];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Precompute log values
    for (int i = 2; i < MAXN; ++i)
        lg[i] = lg[i / 2] + 1;

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        for (int i = 0; i < n; ++i)
            cin >> a[i], st[i][0] = a[i];

        // Build Sparse Table
        for (int j = 1; (1 << j) <= n; ++j) {
            for (int i = 0; i + (1 << j) <= n; ++i) {
                st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
            }
        }

        int q;
        cin >> q;
        while (q--) {
            int l;
            int k;
            cin >> l >> k;
            --l;

            if (a[l] < k) {
                cout << -1 << " ";
                continue;
            }

            int lo = l, hi = n - 1, ans = -1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                int val = get_and(l, mid);
                if (val >= k) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }

            if (ans == -1) cout << -1 << " ";
            else cout << ans + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}
