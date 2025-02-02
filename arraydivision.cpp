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
bool possible(ll m,vector<long long> &v,ll k)
{
    ll t=1,cur=0;
    ll n=v.size();
    
    for(ll i=0;i<n;i++)
    {
        if(v[i]>m)
        {
            return false;
        }
        else if(v[i]+cur<=m)
        {
            cur+=(ll)v[i];
        }
        else{
            cur=(ll)v[i];
            t++;
        }
    }

    if(t<=k)
    return true;
    return false;
}
int main()
{
  fast;
    ll n,k;
    cin>>n>>k;
    vector<long long> v(n);
    for(long long i=0;i<n;i++){
        cin>>v[i];
    }
    ll l=1,r=1e15;
    // for(auto i:v)
    // {
    //     r+=i;
    // }
    
    long long ans=0;
    while(l<=r)
    {
        ll mid=l+(r-l)/2;
        if(possible(mid,v,k))
        {
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }

    }
   
    cout<<ans<<endl;
  return 0;

}
