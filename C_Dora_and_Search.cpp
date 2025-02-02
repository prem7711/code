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
        int n;
        cin >> n;
        vi v(n);
        int maxi = INT_MIN, mini = INT_MAX;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i] > maxi)
                maxi = v[i];
            if (v[i] < mini)
                mini = v[i];
            mp[v[i]] = i;
        }
        int l = 0,r = n - 1;
        bool a = true;
        while (mp.size() > 0)
        {
            auto i1 = mp.begin()->first;
            auto i2 = mp.rbegin()->first;
            if (v[l] == i1 || v[l] == i2)
            {
                mp.erase(v[l]);
                l++;
            }
            else if (v[r] == i1 || v[r] == i2)
            {
                mp.erase(v[r]);
                r--;
            }
            else
            {
                cout << l + 1 << " " << r + 1 << endl;
                a = false;
                break;
            }
        }
        if (a)
            cout << "-1" << endl;
    }
    return 0;
}
