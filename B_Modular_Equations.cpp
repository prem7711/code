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
    int a, b;
    cin >> a >> b;
    if ((a == 0 && b == 0) || a - b == 0)
    {
        cout << "infinity" << endl;
    }
    else
    {
        int r = a - b;
        vector<int> v;
        int ans = 0;
        for (int i = 1; i * i <= r; i++)
        {
            if (r % i == 0)
            {
                if (i > b)
                    ans++;
                if (r / i != i && r / i > b)
                    ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
