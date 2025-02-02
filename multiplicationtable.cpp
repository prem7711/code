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
bool isvalid(long long m,long long n,long long k)
{
    long long cnt=0;
   for(long long i=1;i<=n;i++)
   {
     cnt=cnt+min(m/i,n);
   }
   if(cnt>=k)
   return true;
   return false;
}
int main()
{
  fast;
   long long n;
   cin>>n;
   long long l=1,r=n*n;
   long long k=r/2+1,ans=0;
   while(l<=r)
   {
       long long m=l+(r-l)/2;
       if(isvalid(m,n,k))
       {
           ans=m;
           r=m-1;
       }
       else{
           l=m+1;
       }
   }
   cout<<ans<<endl;
  return 0;

}
