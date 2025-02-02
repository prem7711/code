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
        ll n, l, r;
        cin >> l >> r;
        vector<long long> v;
        bool valid = false;
        for (long long i = 1; i < -n; i++)
        {
            // find factor in l to r
            long long c = l / i;
            long long rem = c % i;
            long long ans = c * i;
            ans = ans + (i - rem);
            if (ans <= r)
                v.push_back(ans);
            else
            {
                valid = true;
                break;
            }
        }
        if (valid)
        {
            cout << "NO";
        }
        else
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
        }
        //  cout
        cout << endl;
    }
    return 0;
}
