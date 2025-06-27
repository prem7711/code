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
    ll n,k;
    cin>>n>>k;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];
    
    vector<ll>ans(31,0);

    for(ll i=30;i>=0;i--)
    {
        for(ll j=0;j<n;j++){
            ll val=((v[j])&(1<<i));
            if(val>0)
            ans[i]+=1;
        }
    }
    ll cur=0;
    for(ll i=30;i>=0;i--)
    {
        if(ans[i]==n)
        {
           cur=((cur)|(1<<i));
        }
        else if(ans[i]+k>=n){
            ll req=n-ans[i];
            k-=req;
             cur=((cur)|(1<<i));
        }
    }

    // for(int i=0;i<5;i++)
    // cout<<ans[i]<<" ";

    cout<<cur<<endl;
  }
  return 0;

}
