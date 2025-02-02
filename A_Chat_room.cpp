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
    string str;
    cin >> str;
    int n = (int)str.size();
    bool a = false;
    int k = 4;
    for (int i = n - 1; i >= 0; i--)
    {
        if (k == 4 && str[i] == 'o')
        {
            k--;
        }
        else if (k == 3 && str[i] == 'l')
        {
            k--;
        }
        else if (k == 2 && str[i] == 'l')
        {
            k--;
        }
        else if (k == 1 && str[i] == 'e')
        {
            k--;
        }
        else if (k == 0 && str[i] == 'h')
        {
            k--;
        }
    }
    if (k < 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
