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
const int N = 1e6 + 1;
int arr[N];
int main()
{
    fast;
    ll n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x]++;
    }
    int ans = 1;
    for (int i = 1e6; i > 0; i--)
    {
        int ct = 0;
        for (int j = i; j < N; j += i)
        {
            ct += arr[j];
        }
        if (ct > 1)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
