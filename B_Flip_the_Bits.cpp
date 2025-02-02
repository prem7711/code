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
    string s1,s2;
    cin>>s1>>s2;
    int zero=0,one=0,pos=-1,d=0,ans=0;
    bool res=true;
    for(int i=0;i<n;i++)
    {
       if(s[i]=='0')
       zero++;
       else
       one++;
       if(s1[i]!=s2[i])
       {
        d++;
       }
       if(s1[i]==s2[i])
       {
        pos=i
       }
       if(zero==one && pos!=-1)
       {
           int l=i-pos;
           if(l==d)
           {
               ans
           }

       }

    }
  }
  return 0;

}
