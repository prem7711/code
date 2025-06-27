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


    // now checjk whether n can be represented as a factor of 3 numbers
    bool ans=true;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            ans=false;
        }
    }
    ll x=n;
     vector<ll>cur;
    if(ans)
    cout<<"NO"<<endl;
    else{
        ll cnt=0;
       
        for(ll i=2;i*i<=n;i++){
            ll a=0;
            if(n%i==0){
                while(n%i==0){
                    a++;  
                    n/=i;   
                }
                cur.push_back(i);
                if(cur.size()>=3)
                break;
            }
        }
        if(n>1)
        cur.push_back(n);


        if(cur.size()>=3){
            cout<<"YES"<<endl;
            ll c=x/(cur[0]*cur[1]);
            cout<<cur[0]<<" "<<cur[1]<<" "<<c<<endl;
        }
        else if(cur.size()==2){
           // cout<<"prem"<<" ";
            ll a=0,b=0;
            ll z=x;
            while(x%cur[0]==0){
                a++;
                x/=cur[0];

            }
            while(x%cur[1]==0){
                b++;
                x/=cur[1];
            }
            if(a+b<4)
            cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                ll m=z/(cur[0]*cur[1]);
                cout<<cur[0]<<" "<<cur[1]<<" "<<m<<endl;
            }

        }
        else{
              ll z=x,a=0;
            while(x%cur[0]==0){
                a++;
                x/=cur[0];

            }
            if(a<=5)
            cout<<"NO"<<endl;
            else{
              ll a=cur[0],b=a*a, c=z/(a*b);
              cout<<"YES"<<endl;
              cout<<a<<" "<<b<<" "<<c<<endl;
            }
        }
    }


  }
  return 0;

}
