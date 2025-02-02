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
        int n = (int)str.size();
        int j = n - 1;
        while (j > 0)
        {
            int cur = str[j] - '0';
            int pre = str[j - 1] - '0';
            if (pre > cur && (cur % 2 != pre % 2))
            {
                char c1 = str[j];
                char c2 = str[j - 1];
                str[j] = c2;
                str[j - 1] = c1;
            }
            j--;
        }
        cout << str << endl;
    }
    return 0;
}
