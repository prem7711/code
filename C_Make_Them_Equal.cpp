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
        char ch;
        cin >> ch;
        string str;
        cin >> str;
        int d = 0, last = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            if (str[i] != ch)
            {
                d++;
                last = i;
                pos.push_back(i + 1);
            }
        }
        if (d == 0)
            cout << "0" << endl;
        else if (d == 1)
        {
            if (str[n - 1] == ch)
            {
                cout << "1" << endl;
                cout << n << endl;
            }
            else
            {
                cout << "1" << endl;
                cout << n - 1 << endl;
            }
        }
        else
        {
            bool a = false;
            for (int i = n / 2 + 1; i < n; i++)
            {
                if (mp.find(i) == mp.end())
                {
                    a = true;
                    ans = i;
                    break;
                }
            }
            if (a)
            {
                cout << "1" << endl;
                cout << i << endl;
            }
            else
            {
                cout << "2" << endl;
                cout << n << " " << n - 1 << endl;
            }
        }
    }
    return 0;
}
