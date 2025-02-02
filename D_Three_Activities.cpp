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

int helper(vector<pair<int, pair<int, int>>> &v, vector<int> vis, int i, int ct, vector<int> vis2)
{
    int n = v.size();
    if (i >= n && ct == 3)
    {
        return 0;
    }
    if (i >= n)
    {
        return -1e5;
    }
    int a = 0, b = 0;
    // take
    int val = v[i].first;
    int day = v[i].second.first;
    int k = v[i].second.second;
    if (vis[k] == 0 && vis2[day] == 0)
    {
        vis[k] = 1;
        vis2[day] = 1;
        a = val + helper(v, vis, i + 1, ct + 1, vis2);
    }

    b = helper(v, vis, i + 1, ct, vis2);
    return max(a, b);

    // not take
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> v1, v2, v3;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v1.push_back({a, i});
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v2.push_back({a, i});
        }
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v3.push_back({a, i});
        }
 
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());
        int ct = 1;
        
         vector<pair<int, pair<int, int>>> v;
        for (int i = n - 3; i < n; i++)
        {

            if (mp.find(v1[i].second) == mp.end())
            {
                mp[v1[i].second] = ct;
                ct++;
                v.push_back({v1[i].first, {mp[v1[i].second], 0}});
            }
            else
            {
                v.push_back({v1[i].first, {mp[v1[i].second], 0}});
            }

            if (mp.find(v2[i].second) == mp.end())
            {
                mp[v2[i].second] = ct;
                ct++;
                
                v.push_back({v2[i].first, {mp[v2[i].second], 1}});
            }
            else
            {
                v.push_back({v2[i].first, {mp[v2[i].second], 1}});
            }

            if (mp.find(v3[i].second) == mp.end())
            {
                mp[v3[i].second] = ct;
                ct++;
                v.push_back({v3[i].first, {mp[v3[i].second], 2}});
            }
            else
            {
                v.push_back({v3[i].first, {mp[v3[i].second], 2}});
            }
        }
        
        
          vector<int> vis(3, 0);
        vector<int> vis2(10, 0);
        
         int a = helper(v, vis, 0, 0, vis2);
        cout << a << endl;
       
    }
    return 0;
}
