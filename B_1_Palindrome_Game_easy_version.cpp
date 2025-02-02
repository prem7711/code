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
        string str;
        cin >> str;
        int z = 0;
        for (int i = 0; i < n; i++)
        {
            if (str[i] == '0')
                z++;
        }
        // cout << z << " ";
        if (n % 2 == 1 && str[n / 2] == '0')
        {
            // alice turn;

            if (z % 2 == 0)
            {
                cout << "DRAW" << endl;
            }
            else if (z % 4 == 3)
            {
                cout << "ALICE" << endl;
            }
            else
                cout << "BOB" << endl;
        }
        else
        {
            if (z % 4 == 0)
            {
                cout << "DRAW" << endl;
            }
            else
            {
                cout << "BOB" << endl;
            }
        }
    }
    return 0;
}
