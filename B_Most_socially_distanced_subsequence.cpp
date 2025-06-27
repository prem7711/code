// header files and namespaces
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> v[i];
        }

        ll i = 1;
        ll pre = v[0];
        vector<ll> ans;
        ans.push_back(pre);
        while (i < n)
        {
            if (v[i] < v[i-1])
            {
                // decreasing subsequence
                while (i < n && v[i] < v[i - 1])
                {
                    // cout << i << " ";
                    i++;
                }
                // check on which element you are at present
                if (v.back() != v[i - 1])
                    ans.push_back(v[i - 1]);

                // if (i != n)
                // {
                //     pre = v[i];
                //     i++;
                // }
            }
            else
            {
                while (i < n && v[i] > v[i - 1])
                {
                    // cout << i << " ";
                    i++;
                }
                // check on which element you are at present
                if (v.back() != v[i - 1])
                    ans.push_back(v[i - 1]);
                // if (i != n)
                // {
                //     pre = v[i];
                //     i++;
                // }
            }
            // cout<<i<<" ";
        }
        if (ans.back() != v[n - 1])
            ans.push_back(v[n - 1]);
        cout << ans.size() << endl;
        for (auto &i : ans)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}

// 2
// 3
// 3 2 1
// 4
// 1 3 4 2
