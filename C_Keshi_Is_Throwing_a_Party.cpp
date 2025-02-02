#include <bits/stdc++.h>
using namespace std;

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

bool valid(int m, vector<pair<int, int>> &v)
{
    vector<pair<int, int>> temp;
    // First pass: Filter pairs satisfying b >= i for each i
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i].second >= temp.size())
        {
            temp.push_back(v[i]);
        }
    }

    // Second pass: Filter remaining pairs satisfying a >= r
    vector<pair<int, int>> final_temp;
    for (int i = 0; i < temp.size(); ++i)
    {
        int r = temp.size() - 1 - i; // Corrected the computation of r
        if (temp[i].first >= r)
        {
            final_temp.push_back(temp[i]);
        }
    }

    return final_temp.size() >= m;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }
        int l = 0, r = n, ans = -1;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (valid(m, v))
            {
                ans = m;
                l = m + 1;
            }
            else
            {
                r = m - 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
