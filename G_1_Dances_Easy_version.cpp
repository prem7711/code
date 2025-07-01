#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        a[0] = k;
        for (int i = 1; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int i = 0, j = 0;
        int validPairs = 0;
        while (i < n && j < n) {
            if (a[i] < b[j]) {
                validPairs++;
                i++;
                j++;
            } else {
                j++;
            }
        }

        int removals = n - validPairs;
        cout << removals << "\n";
    }
    return 0;
}
