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
    ll n;
    cin>>n;
    vector<ll>v(n);
    for(ll i=0;i<n;i++)
    cin>>v[i];

    priority_queue<ll>pq;
    ll sum=0;
    for(ll i=0;i<n;i++){
        sum+=v[i];
        pq.push(v[i]);
    }
    vector<ll>ans;

    for(ll i=0;i<n;i++){
        ll cur=sum-v[i];

        // pop top tw elemnts from priority queue

        ll a=pq.top();
        pq.pop();

        ll b=pq.top();
        pq.pop();


        // now delete 

        if(a==v[i]){
             if(cur==2*b)
             ans.push_back(i+1);
        }
        else if(b==v[i]){
            if(cur==2*a)
            ans.push_back(i+1);
        }
        else{
            if(2*a==cur)
            ans.push_back(i+1);
        }
        pq.push(a);
        pq.push(b);

    }
    cout<<ans.size()<<endl;
    for(auto i:ans)
    cout<<i<<" ";
  return 0;

}
