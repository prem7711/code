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
bool ispalindrome(vector<int> &v)
{
    int l = 0, r = v.size() - 1;
    while (l < r)
    {
        if (v[l] != v[r])
            return false;
        else
        {
            l++;
            r--;
        }
    }
    return true;
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
        vi v(n);
        REP(i, 0, n - 1)
        {
            cin >> v[i];
        }
        int i = 0, j = n - 1, l = -1, r = -1;
        while (i < j)
        {
            if (v[i] == v[j])
            {
                i++;
                j--;
            }
            else
            {
                l = v[i];
                r = v[j];
                break;
            }
        }
        vi v1, v2;
        for (int i = 0; i < n; i++)
        {
            if (v[i] == l)
            {
                v2.push_back(l);
            }
            else if (v[i] == r)
            {
                v1.push_back(r);
            }
            else
            {
                v1.push_back(v[i]);
                v2.push_back(v[i]);
            }
        }
        bool a = ispalindrome(v1) || ispalindrome(v2);
        if (a || l == -1)
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
