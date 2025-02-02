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
    int n;
    cin>>n;
    vi v1(n),v2(n);
    REP(i,0,n-1)
    cin>>v1[i];
    REP(i,0,n-1)
    cin>>v2[i];
    int cur=0,idx=-1;
    for(int i=0;i<n;i++)
    {
        if(v1[i]!=v2[i])
        {
            cur++;
            idx=i;
           int j=i;
           while(j+1<n && v2[j]<=v2[j+1])
           {
            cur++;
            j++;
           }
           break;
        }
    }
        int x=idx;
        int y=idx+cur;
        for(int j=idx-1;j>=0;j--)
        {
            if(v1[j]<v1[j+1])
           {
            cur++;
            idx--;
           }
           else
           break;
        }
    cout<<x+1<<" "<<y+1<<endl;
  }

  return 0;

}
