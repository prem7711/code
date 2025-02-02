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
    vector<int> v;
    for (int i = 1; i < n; i++)
    {
        cout << "?"
             << " " << i << " " << i + 1 << endl;
        int a;
        cin >> a;
        v.push_back(a);
    }
    cout << "?"
         << " "
         << "1"
         << " "
         << "3" << endl;
    int a;
    cin >> a;
    int t = v[0] + v[1];
    int x = t - a;
    // 2nd element t
    // 1st element

    vector<int> ans;
    ans.push_back(v[0] - x);
    ans.push_back(x);
    for (int i = 1; i < n - 1; i++)
    {
        ans.push_back(v[i] - ans.back());
    }
    cout << "! ";
    for (auto i : ans)
        cout << i << " ";
    cout << endl;

    return 0;
}
