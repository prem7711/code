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
  ll n,m;
  cin>>n>>m;
  vector<ll>v1(n),v2(m);
  for(ll i=0;i<n;i++)
  {
    cin>>v1[i];
  }
  for(ll i=0;i<m;i++)
  {
    cin>>v2[i];
  }
  ll gcd=INT_MAX;
  for(ll i=1;i<n;i++)
  {
     if(i==1)
     {
        gcd=v1[i]-v1[0];
     }
     else 
     {
        gcd=__gcd(gcd,v1[i]-v1[0]);
     }
  }
   vector<ll>ans;
   for(ll i=0;i<m;i++)
   {
    ll a=v1[0]+v2[i];
    if(gcd!=INT_MAX)
    {
        a=__gcd(a,gcd);
    }
    ans.push_back(abs(a));
   }
   for(auto i:ans)
   cout<<i<<" ";
   cout<<endl;
  return 0;

}
