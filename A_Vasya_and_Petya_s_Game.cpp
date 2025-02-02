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

    return 0;
    int n=1000;
    vector<int>prime(1001,1);
    for(int p=2;p*p<=n;p++)
    { 
    if (prime[p] == 1) 
    {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
     }
    }
    vector<int>p;
    for(int i=2;i<=n;i++)
    {
        if(prime[i]==1)
        {
            p.push_back(i);
        }
    }
    int ans=0;
    vector<int>v;
    for(int i=0;i<p.size();i++)
    {
        int a=p[i];
        while(a<=t)
        {
          v.push_back(a);
          a=a*p[i];
        }
    }
    cout<<v.size()<<endl;
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;
  return 0;
}
