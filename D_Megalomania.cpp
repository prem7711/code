#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

bool cmp(pair<ll, ll> &a, pair<ll, ll> &b)
{
    return a.second < b.second; // Correct comparator to sort by deadline
}

int main()
{
    fast;
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v[i] = {a, b};
    }

    sort(v.begin(), v.end(), cmp); // Sort jobs by deadline

    ll currentTime = 0;
    bool canCompleteAllJobs = true;

    for (ll i = 0; i < n; i++)
    {
        currentTime += v[i].first; // Add the time required for the current job
        if (currentTime > v[i].second)
        { // Check if the job can be completed before its deadline
            canCompleteAllJobs = false;
            break;
        }
    }

    if (canCompleteAllJobs)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
