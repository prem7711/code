#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        unordered_set<bitset<200005>> s;
        vector<bitset<200005>> all_bits;
        vector<int> count(200005, 0);

        for (ll i = 0; i < n; i++) {
            ll k;
            cin >> k;
            bitset<200005> b;
            while (k--) {
                ll x;
                cin >> x;
                b.set(x);
                count[x]++;
            }
            s.insert(b);
            all_bits.push_back(b);
        }

        for (int i = 0; i < 200005; i++) {
            if (count[i] == 1) {
                for (auto it = s.begin(); it != s.end();) {
                    if (it->test(i)) {
                        it = s.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

        if (!s.empty())
            cout << "Yes\n";
        else
            cout << "No\n";
    }

    return 0;
}
