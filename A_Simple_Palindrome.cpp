// header files and namespaces
#include <bits/stdc++.h>
using namespace std;

// code shortcuts
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define f first
#define s second
#define PB push_back
#define MP make_pair
#define len(s) (int)s.size()
#define print(x) cout << x << '\n'
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define fast                    \
  ios_base::sync_with_stdio(0); \
  cin.tie(0);                   \
  cout.tie(0);

ll mod = 1000000007;

// code
int main()
{
  fast;
  ll t;
  cin >> t;
  while (t--)
  {

    int n;
    cin >> n;
    string str;
    string temp = "aeiou";
    bool dir = true;
    if (n == 1)
      cout << "a" << endl;
    else if (n == 2)
    {
      cout << "ae" << endl;
    }
    else if (n == 3)
    {
      cout << "aei" << endl;
    }
    else if (n == 4)
    {
      cout << "aeio" << endl;
    }
    else if (n == 5)
    {
      cout << "aeiou" << endl;
    }
    else
    {
      int f = n / 5;
      int r=n%5;
      for (int i = 0; i < f; i++)
      {
        str.push_back('a');
      }
      if(r>0)
      {
        str.push_back('a');
        r--;
      }
      for (int i = 0; i < f; i++)
      {
        str.push_back('e');
      }
      if(r>0)
      {
        str.push_back('e');
        r--;
      }
      for (int i = 0; i < f; i++)
      {
        str.push_back('i');
      }
      if(r>0)
      {
        str.push_back('i');
        r--;
      }
      for (int i = 0; i < f; i++)
      {
        str.push_back('o');
      }
      if(r>0)
      {
        str.push_back('u');
        r--;
      }
      for (int i = 0; i < f; i++)
      {
        str.push_back('u');
      }
      cout << str << endl;
    }
  }
  return 0;
}
