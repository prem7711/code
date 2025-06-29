#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;

        ll twos = 0, fives = 0, x = n;

        // Count how many 2s and 5s in n
        while (x % 2 == 0) x /= 2, twos++;
        while (x % 5 == 0) x /= 5, fives++;

        ll k = 1;

        // Balance excess 5s with 2s in k
        while (fives > twos && k * 2 <= m) k *= 2, twos++;
        while (twos > fives && k * 5 <= m) k *= 5, fives++;

        // Multiply k with 10 as much as possible
        while (k * 10 <= m) k *= 10;

        // Fill the rest to be ≤ m
        ll factor = m / k;
        k *= factor;

        cout << n * k << '\n';
    }

    return 0;
}
