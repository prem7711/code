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
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int g = abs(v[0] - v[n - 1]);
        int i = 1, j = n - 2;
        while (i < j)
        {
            int dif = abs(v[i] - v[j]);
            i++;
            j--;
            g = __gcd(g, dif);
        }
        bool ans = true;
        int i = 0, j = n - 1;
        while (i < n)
        {
            if (v[i] != v[j])
            {
                ans = false;
                break;
            }
            i++;
            j--;
        }
        if (ans == true || g == 1)
            cout << "0" << endl;
        else
            cout << g << endl;
    }
    return 0;
}
