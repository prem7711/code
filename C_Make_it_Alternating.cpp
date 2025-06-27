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
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

ll m = 998244353;
const int N = 2e5 + 5;
ll fac[N];

void pre() {
    fac[0] = 1;
    REP(i, 1, N - 1) {
        fac[i] = fac[i - 1] * i % m;
    }
}

// code
int main() {
    fast;
    pre();
    ll t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        ll n = str.size();
        ll ops = 0, ways = 1;
        ll i = 0;

        while (i < n) {
            ll j = i;
            while (j < n && str[j] == str[i]) j++;
            ll ct = j - i;
            ops += ct - 1;
            ways = (ways * ct % m ) % m;  // ct * (ct-1)!
            i = j;
        }
        ways=(ways*fac[ops])%m;

        cout << ops << " " << ways << '\n';
    }
    return 0;
}
