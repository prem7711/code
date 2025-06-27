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
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll mod = 1000000007;

// code
int main()
{
    fast;
    string s;
    cin >> s;
    ll i = 1, n = s.size();

    while (i < n)
    {
        if (s[i] == s[i - 1])
        {
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                if (ch != s[i - 1] && (i + 1 >= n || ch != s[i + 1]))
                {
                    s[i] = ch;
                    break;
                }
            }
        }
        i++; // fix: increment by 1, not 2
    }

    cout << s << '\n';
    return 0;
}
