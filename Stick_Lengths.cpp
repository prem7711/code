#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n;
    cin >> n;
    vector<ll> sticks(n);

    for (ll i = 0; i < n; i++)
    {
        cin >> sticks[i];
    }

    // Sort the sticks to find the median
    sort(sticks.begin(), sticks.end());

    // Find the median
    ll median = sticks[n / 2];

    // Calculate the minimum total cost
    ll total_cost = 0;
    for (ll i = 0; i < n; i++)
    {
        total_cost += abs(sticks[i] - median);
    }

    // Output the result
    cout << total_cost << '\n';

    return 0;
}
