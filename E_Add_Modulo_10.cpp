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
        ll k = -1;
        for (ll i = 0; i < n; i++)
        {
            if (v[i] % 10 == 1)
            {
                v[i] += 21;
            }
            else if (v[i] % 10 == 2)
            {
                continue;
            }
            else if (v[i] % 10 == 3)
            {
                v[i] += 9;
            }
            else if (v[i] % 10 == 4)
            {
                v[i] += 18;
            }
            else if (v[i] % 10 == 5)
            {
                v[i] += 5;
                k = v[i];
            }
            else if (v[i] % 10 == 6)
            {
                v[i] += 6;
            }
            else if (v[i] % 10 == 7)
            {
                v[i] += 25;
            }
            else if (v[i] % 10 == 8)
            {
                v[i] += 14;
            }
            else if (v[i] % 10 == 9)
            {
                v[i] += 23;
            }
            else
            {
                k = v[i];
            }
        }

        sort(v.begin(), v.end());
        bool ans = true;
        if (k != -1)
        {
            for (ll i = 1; i < n; i++)
            {
                if (v[i] != v[i - 1])
                {
                    ans = false;
                    break;
                }
            }
        }

        // for (auto i : v)
        //     cout << i << " ";

        // cout << endl;

        for (ll i = 1; i < n; i++)
        {
            ll dif = v[i] - v[i - 1];
            if (dif == 0 || (dif % 20 == 0))
                continue;
            else
            {
                ans = false;
                break;
            }
        }
        if (ans)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
