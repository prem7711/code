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
bool possible(ll mid, vector<ll>& v, ll w) {
     map<ll, int> freq;
    for (ll x : v) {
        freq[x]++;
    }

    int total = v.size();

    for (int bin = 0; bin < mid && total > 0; bin++) {
        ll rem = w;

        // Try to fill current bin
        auto it = freq.rbegin();
        while (it != freq.rend()) {
            ll val = it->first;
            while (it->second > 0 && val <= rem) {
                rem -= val;
                it->second--;
                total--;
            }
            ++it;
        }
    }


    return total==0;
}
int main()
{
  fast;
  ll t;
  cin>>t;
  while(t--)
  {
    ll n,w;
    cin>>n>>w;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];

    sort(v.begin(),v.end());

    ll l=1,r=1e10,ans=1e10;
    while(l<=r){
        ll mid=l+(r-l)/2;
        if(possible(mid,v,w)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }

    }
    cout<<ans<<endl;

  }
  return 0;

}
