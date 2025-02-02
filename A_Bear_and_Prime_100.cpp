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
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

ll mod = 1000000007;

// code
int main()
{
    fast;
    vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 4, 9, 25, 36, 49};
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
        string str;
        cin >> str;
        if (str == "yes")
            cnt++;
        if (cnt >= 2)
            break;
    }
    if (cnt >= 2)
        cout << "composite" << endl;
    else
    {
        cout << "prime" << endl;
    }

    return 0;
}
