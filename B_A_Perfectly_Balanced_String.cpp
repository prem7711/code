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
        vector<int> v1(26, -1), v2(26, 0);
        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            v2[idx] = 1;
        }
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            int idx = str[i] - 'a';
            v2[idx] = 1;
            if (v1[idx] != -1)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (v2[j] == 1 && v1[j] < v1[idx])
                    {
                        ans = false;
                        break;
                    }
                }
            }
            v1[idx] = i;
        }
        ans == true ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}
