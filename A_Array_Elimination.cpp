// header files and namespaces
#include <bits/stdc++.h>
#include <numeric>
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

ll gcd(ll a, ll b)
{
    if (a < b)
    {
        ll c = a;
        a = b;
        b = c;
    }
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
// code
int main()
{
    fast;
    ll test;
    cin >> test;
    while (test--)
    {
        ll n;
        cin >> n;
        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];
        vector<ll> t(31, 0);
        ll a = 0, b = 0;
        for (ll i = 30; i >= 0; i--)
        {
            ll cnt = 0;
            for (ll j = 0; j < n; j++)
            {
                if ((v[j] & (1 << i)) > 0)
                    cnt++;
            }
            t[i] = cnt;
        }
        for (auto i : v)
            if (i == 0)
                a++;


        // for(int i=0;i<10;i++)
        // cout<<t[i]<<" ";

        if (a == n)
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
        }
        else
        {
            //cout<<"prem";
            for (ll i = 0; i < 31; i++)
            {
                if (i == 0)
                    b = t[i];
                else
                {
                    b = gcd(b, t[i]);
                }
            }
            // cout<<b<<" ";

            //
            vector<ll> f;
            for (ll i = 1; i * i <= b; i++)
            {
                if (b % i == 0)
                {
                    f.push_back(i);
                    if (i * i != b)
                    {
                        f.push_back(b / i);
                    }
                }
            }
            //cout<<f.size();
            sort(f.begin(), f.end());
            for (auto i : f)
                cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
