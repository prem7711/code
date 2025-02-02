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
        string str;
        cin >> str;
        int n = len(str);
        vector<int> first(n, -1), last(n, n - 1);
        int pos = n;
        ll ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
            {
                pos = i;
            }
            first[i] = pos;
        }
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            if (str[i] == '1' && str[j] != '0')
            {
                while (j < n && str[j] != '0')
                {
                    j++;
                }
            }
            if (j < n)
            {
                last[i] = j;
            }
            if (i == j)
            {
                i++;
                j++;
            }
            else
            {
                i++;
            }
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (str[i] == '0')
            {
                pos = n - 1 - i;
                break;
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (str[i] != '0')
            {
                // length of its longest row
                int length = 0;
                if (first[i] == n)
                {
                    length = min(n, i + 1 + pos);
                }
                else
                {
                    length = i - first[i];
                }
                // calculating answer
                int col = min(n - 1 - i, last[i] - i);
                // cout << col << "a" << length << " ";
                ans = max(ans, col * 1ll * length);
                ans = max(ans, max(col * 1ll, length * 1ll));
            }
            //  cout << ans << " ";
        }
        cout << ans << endl;
        // cout<<endl;
    }
    return 0;
}