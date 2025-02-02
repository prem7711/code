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

int helper(int l, int m, vector<int> &v)
{
    int sum =0;
    cout <<"? "<<m<<" ";
    int s = 0;
    for (int i = 1; i <= m; i++)
    {
        cout << i << " ";
        sum+=v[i];
    }
    cout << endl;
    int a;
    cin >> a;
    // cout<<sum<<" "<<a<<"  ";
    if (sum == a)
    {
        return false;
    }
    return true;
}
int main()
{
    fast;
    int t;
    cin >> t;
    while (t--)
    {

        int n;
        cin >> n;
        vector<int> p(n + 1);
        vector<int> v(n + 1);
        int ans = -1;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            p[i] = p[i - 1] + v[i];
        }
        int l = 1, r = n;
        while (l <= r)
        {
            int m = l + (r - l) / 2;
            if (helper(1, m, v) == true)
            {
                ans = m;
                r = m - 1;
            }
            else
            {
                l = m + 1;
            }
        }
        cout << "! " << ans << endl;
    }

    return 0;
}
