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
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k, q;
        cin >> n >> k >> q;
        vi v(n), v2;
        REP(i, 0, n - 1)
        {
            cin >> v[i];
            if (v[i] > q)
            {
                v2.push_back(i);
            }
        }
       
       
       
        ll ans = 0, i = 0, pre = -1;
            while (i != v2.size())
            {
                 int ele = v2[i] - pre-1;
                // cout<<v2[i]<<"h"<<pre<<" ";
                pre = v2[i];
                
                if (ele >= k)
                {
                    ans = ans + ((ele - k + 1) * 1ll * (ele - k + 2)) / 2;
                }
                i++;
            }
        //  cout<<ans<<"  ";
        int rem = 0;
        if(v2.size()==0)
        {
            ans = ans + ((n - k + 1) * 1ll * (n - k + 2)) / 2;
        }
        else
        {
           rem=n-1-v2.back();
           if(rem>=k)
           ans = ans + ((rem - k + 1) * 1ll * (rem - k + 2)) / 2;  
        }
        
        cout << ans << endl;
    }
    return 0;
}
