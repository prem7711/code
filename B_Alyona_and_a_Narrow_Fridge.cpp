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

bool possible(ll mid,vector<ll>&v,ll h){
     priority_queue<ll>pq;
     for(ll i=0;i<mid;i++)
     pq.push(v[i]);

     while(!pq.empty()){
        ll a=0,b=0;
        a=pq.top();
        pq.pop();
        if(!pq.empty())
        {
          b=pq.top();
          pq.pop();
        }
        if(max(a,b)>h)
        return false;

        h-=max(a,b);
     }
     return true;
}
// code
int main()
{
  fast;
  ll n,h;
  cin>>n>>h;
  vector<ll>v(n);

  for(ll i=0;i<n;i++)
  cin>>v[i];

  ll l=1,r=n,ans=0;;

  while(l<=r){

    ll mid=l+(r-l)/2;

    if(possible(mid,v,h)){
        ans=mid;
        l=mid+1;
    }
    else{
        r=mid-1;
    }
  }
  
  cout<<ans<<endl;


  return 0;

}
