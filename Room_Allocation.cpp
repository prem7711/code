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

int main()
{
    fast;
    ll n;
    cin >> n;

    vector<pair<ll, ll>> v;
    for (ll i = 0; i < n; i++)
    {
        ll a, b;
        cin >> a >> b;
        v.push_back({b, a}); // store intervals as (end_time, start_time)
    }
    sort(v.begin(), v.end()); // sort intervals by end_time

    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq; // min-heap
    pq.push({v[0].first, 1});                                                     // initialize with the first interval and room 1

    vector<ll> t(n); // to store the room assignments
    t[0] = 1;
    ll max_rooms = 1;

    for (int i = 1; i < n; i++)
    {
        if (pq.top().first < v[i].second)
        {
            // Current room is free for the new interval
            t[i] = pq.top().second; // Assign the room from the top of the heap
            pq.pop();
        }
        else
        {
            // Need a new room
            t[i] = pq.size() + 1;
        }
        pq.push({v[i].first, t[i]});               // Push the new interval's end time and room number
        max_rooms = max(max_rooms, (ll)pq.size()); // Update the maximum number of rooms used
    }

    cout << max_rooms << endl; // Output the maximum number of rooms used

    for (auto room : t)
        cout << room << " "; // Output the room assignments
    cout << endl;

    return 0;
}
