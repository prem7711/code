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
ll helper(vector<ll>&v,ll idx,vector<ll>&dp){
    ll s=v.size();
    if(idx==s)
    return 0;
    if(idx>s)
    return 1e9;
    if(dp[idx]!=INT64_MAX)
    return dp[idx];
    //  now i am at current index at idx 
    // i have two choice 
    // now i am deleting rhthat idx

    ll a=1+helper(v,idx+1,dp);
    ll b=helper(v,v[idx]+1+idx,dp);
    return dp[idx]=min(a,b);
}
int main()
{
  fast;
  ll t;
  cin>>t;
  while(t--)
  {
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    // i will opt for dp approach
    vector<ll>dp(n,INT64_MAX);
    ll ans=helper(v,0,dp);
    cout<<ans<<endl;
  }
  return 0;

}
