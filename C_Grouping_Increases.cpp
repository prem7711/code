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
        ll n;
        cin >> n;
        vector<ll> v(n);

        for (ll i = 0; i < n; i++)
            cin >> v[i];

        // maintain two vector
        ll ans = 0;
        ll j=1;
        vector<ll> v1, v2;
        v1.push_back(v[0]);
        while(j<n){
            if(v[j]<=v1.back()){
                v1.push_back(v[j]);
                j++;
            }
            else
            break;
        }

        if (j < n)
        {
            if (v[j] <=v1[0])
            {

                v2.push_back(v1[0]);
            }
            else
            {
                v2.push_back(v[j]);
                j++;
            }
        }

            
        for (ll i = j; i < n; i++)
        {
            if (v[i] <= v1.back() || (v2.back() >= v[i]))
            {

                ll m = min(v1.back(), v2.back());
           
                // smaller than both
               if(v[i]<=m){

                if (v1.back() == m)
                {
                    v1.push_back(v[i]);
                }
                else
                {
                    v2.push_back(v[i]);
                }

               }
               else if(v[i]<=v1.back()){
                v1.push_back(v[i]);
               }
               else{
                v2.push_back(v[i]);
               }
  
            }
            else
            {
                        ll m = max(v1.back(), v2.back());

                        if (v1.back() == m)
                        {
                            v2.push_back(v[i]);
                            ans++;
                        }
                        else
                        {
                            v1.push_back(v[i]);
                            ans++;
                        }
            }
        }

        cout << ans << endl;
    }
    return 0;
}
