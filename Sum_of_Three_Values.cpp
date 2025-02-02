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
int main()
{
    fast;
    int n, s;
    cin >> n >> s;
    vector<pi> v; // Vector of pairs to store element and its index
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.PB(MP(x, i + 1)); // Store the element and its 1-based index
    }

    sort(v.begin(), v.end()); // Sort based on the element values
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        int l = i + 1, r = n - 1;
        int req = s - v[i].f;
        while (l < r)
        {
            if (v[l].f + v[r].f == req)
            {
                ans.push_back(v[i].s);
                ans.push_back(v[l].s);
                ans.push_back(v[r].s);
                if (ans.size() == 3)
                    break;
            }
            else if (v[l].f + v[r].f < req)
                l++;
            else
                r--;
        }
        if (ans.size() == 3)
            break;
    }
    if (ans.size() == 3)
    {
        for (auto i : ans)
            cout << i << " ";
        cout << endl;
    }
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
