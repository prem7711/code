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
    ll n;
    cin>>n;
    vector<ll>v1(n),v2(n);
    for(ll i=0;i<n;i++)
    cin>>v1[i];
    v2=v1;
    sort(v2.begin(),v2.end());
    
  }
  return 0;

}
