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
bool valid(int m, vector<int> &v)
{
    int i = v.size() - 1;
    bool cur = true;
    for (int j = m - 1; j >= 0; j--, i--)
    {
        cur &= (v[i] > v[j] && v[i - 1] > v[j]);
    }
    return cur;
}
int main()
{
    fast;
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    int cur = 0;
    vector<int> ans(n);
    sort(v.begin(), v.end());

    int i = 1, j = (n + 1) / 2 - 1, answer = 0;

    while (i <= j)
    {
        int m = i + (j - i) / 2;
        if (valid(m, v))
        {
            answer = m;
            i = m + 1;
        }
        else
        {
            j = m - 1;
        }
    }
    i = n - 1, j = answer - 1;
    for (int k = 0; k < n; k++)
    {
        if (k % 2 == 0 || j < 0)
        {
            ans[k] = v[i];
            i--;
        }
        else
        {
            ans[k] = v[j];
            j--;
        }
    }
    cout << answer << endl;
    for (auto i : ans)
        cout << i << " ";

    return 0;
}
