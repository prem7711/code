// header files and namespaces
#include<bits/stdc++.h>
using namespace std;

// code shortcuts
typedef long long ll;
typedef vector<int>vi;
typedef pair<int,int>pi;
#define f first
#define s second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout<<x<<'\n'
#define REP(i,a,b) for(int i=a; i<=b;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

ll mod =1000000007;

// code
int main()
{
  fast;
  ll t;
  cin>>t;
  while(t--)
  {
    long long n;
    cin>>n;
    vector<long long>v(n);
    long long sum=0;
    for(long long i=0;i<n;i++)
    {
        cin>>v[i];
        sum+=v[i];
    }
    long long ans=0,cc=0;
    for(long long i=0;i<n-1;i++)
    {
      cc+=v[i];
      ans=max(ans,__gcd(cc,sum-cc));
    }
     cout<<ans<<endl;
  }
  return 0;

}
