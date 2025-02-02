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
    ll a, b, c;
    cin >> a >> b >> c;
    ll m;
    cin >> m;
    vector<ll> v1, v2;
    for (ll i = 0; i < m; i++)
    {
        ll x;
        string str;
        cin >> x;
        cin >> str;
        if (str == "USB")
        {
            v1.push_back(x);
        }
        else
        {
            v2.push_back(x);
        }
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    // for (auto i : v1)
    //     cout << i << " ";
    // cout << endl;
    // for (auto i : v2)
    //     cout << i << " ";
    // cout << endl;
    ll s = 0, a1 = 0, b1 = 0;

    ll m1 = v1.size(), m2 = v2.size();
    for (ll k = 0; k < min(m1, a); k++)
    {
        s += v1[k];
        a1++;
    }
    for (ll k = 0; k < min(m2, b); k++)
    {
        s += v2[k];
        b1++;
    }
    // cout << s << " ";
    while (c > 0)
    {
        ll x = 1e10, y = 1e10;
        if (a1 < m1)
        {
            x = v1[a1];
        }
        if (b1 < m2)
        {
            y = v2[b1];
        }

        if (x == 1e10 && y == 1e10)
            break;
        if (x <= y)
        {
            a1++;
            s += x;
        }
        else
        {
            b1++;
            s += y;
        }
        c--;
    }
    cout << a1 + b1 << " " << s << endl;

    // now i  need to  get type 3

    return 0;
}
