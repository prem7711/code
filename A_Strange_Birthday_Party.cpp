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
        ll n, m;
        cin >> n >> m;
        vector<ll> v1(n), v2(m);
        for (ll i = 0; i < n; i++)
            cin >> v1[i];

        for (ll i = 0; i < m; i++)
            cin >> v2[i];

        sort(v1.begin(), v1.end());

        ll i = 0, j = n-1, ans = 0,cur=0;

        while (i<=j)
        {

            // req jth index v1[i]-1

           if(cur+1==v1[i]){
            ans+=v2[cur];
             i++;
           }
           else{
            ans+=v2[cur];
            cur++;
            j--;

           }
          // cout<<ans<<" ";
    
        }

        cout << ans << endl;
    }
    return 0;
}
