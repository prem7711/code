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

    int n;
    cin >> n; 
    string str;
    cin >> str;
    unordered_map<char, int> ump, ump2;
    for (int i = 0; i < n; i++)
        ump2[str[i]]++;
    int i = 0, j = 0;
    int ans = INT_MAX;
    while (j < n)
    {
        ump[str[j]]++;
        while (ump.size() == ump2.size() && i <= j)
        {
            // remove ith character
            ans = min(ans, j - i + 1);
            ump[str[i]]--;
            if (ump[str[i]] == 0)
                ump.erase(str[i]);
            i++;
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}
