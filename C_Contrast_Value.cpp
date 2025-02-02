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
        vi v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        int ans = 0, pos = -1, neg = -1, index = 0;
        vector<int> cur;
        cur.push_back(v[0]);
        for (int i = 1; i < n; i++)
        {
            if (v[i] == v[i - 1])
                continue;
            if (v[i] < v[i - 1])
            {
                if (pos == 1)
                {
                    // cout<<"a"<<v[i-1]<<" ";
                    cur.push_back(v[i - 1]);
                    pos = -1;
                    
                }
                neg=1;
               
            }
            if (v[i] > v[i - 1])
            {
                if (neg == 1)
                {
                    //  cout<<"b"<<v[i-1]<<" ";
                    cur.push_back(v[i - 1]);
                    neg = -1;
                }
                pos=1;
            }
        }
        if(cur.back()!=v.back())
        cur.push_back(v.back());
        // cout<<endl;
        // for(auto i:cur)
        // cout<<i<<" ";
        cout << cur.size()<< endl;
    }
    return 0;
}
