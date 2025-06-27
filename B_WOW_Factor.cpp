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
    string str;
    cin>>str;
    ll n=str.size();
    vector<ll>pre(n,0),suf(n,0);
    ll i=1,j=n-2;

    while(i<n){
        if(str[i]==str[i-1] && str[i]=='v')
        {
            pre[i]=pre[i-1]+1;
        }
        else{
            pre[i]=pre[i-1];
        }
        i++;
    }


    while(j>=0){
        if(str[j]==str[j+1] && str[j]=='v')
        {
            suf[j]=suf[j+1]+1;
        }
        else{
            suf[j]=suf[j+1];
        }
        j--;
    }

    ll ans=0;
    for(ll k=1;k<n-1;k++){
        if(str[k]=='o'){
            ans=ans+pre[k]*suf[k];
        }
    }

    cout<<ans<<endl;

  return 0;

}
