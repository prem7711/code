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

void helper(vector<int> &spf)
{
    int N = spf.size() - 1;
    for (int i = 1; i <= N; i++)
        spf[i] = i;
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i) // i is a prime number
        {
            for (int j = i * i; j <= N; j += i)
            {
                if (spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }
}
int main()
{
    fast;
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<int> spf(1e5 + 5, 1);
    helper(spf);
    unordered_map<int, int> u, u2;
    for (ll i = 0; i < m; i++)
    {
        string str;
        getline(cin, str);
        char ch = str[0];
        string s = str.substr(2);
        int k = stoi(s);
        int k1 = k;
        // cout<<k<<endl;
        if (ch == '+')
        {
            vector<int> t;
            while (k != 1)
            {
                int a = spf[k];
                while (k % a == 0)
                {
                    k /= a;
                }
                if (a != 1)
                {
                    t.push_back(a);
                }
            }
            int ans = -1;
            for (auto i : t)
            {
                if (u.find(i) != u.end())
                {
                    ans = u[i];
                }
            }
            if (u2[k1] != 0)
                cout << "Already on" << endl;
            else if (ans != -1)
            {
                cout << "Conflict with " << ans << endl;
                u2[k1] = 0;
            }
            else
            {
                for (auto i : t)
                {
                    u[i] = k1;
                }
                cout << "Success" << endl;
                u2[k1] = 1;
            }

            // now check whether it collides
        }
        else
        {
            if (u2[k1] == 0)
            {
                cout << "Already off" << endl;
            }
            else
            {

                vector<int> t;
                while (k != 1)
                {
                    int a = spf[k];
                    while (k % a == 0)
                    {
                        k /= a;
                    }
                    if (a != 1)
                    {
                        t.push_back(a);
                    }
                }

                for (auto i : t)
                {
                    u[i] = 0;
                    u.erase(i);
                }
                u2[k1] = 0;
                cout << "Success" << endl;
            }
        }
    }

    return 0;
}
