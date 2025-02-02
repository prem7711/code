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
        bool ans = true;
        ll sum = 0;
        sort(v.begin(), v.end());
        for (ll i = 0; i < n; i++)
        {
            if (i == 0)
            {
                if (v[i] != 1)
                {
                    // cout<<"hi"<<"  ";
                    ans = false;
                    break;
                }
                sum += v[i];
            }
            else
            {
                if (v[i] > sum)
                {
                    // cout<<2*sum<<" "<<v[i]<<"   ";
                    ans = false;
                    break;
                }
                else
                {
                    sum += v[i];
                }
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
