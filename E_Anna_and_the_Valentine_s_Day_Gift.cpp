#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

// Count trailing zeros in base 10
int trailingZeros(ll x)
{
    int cnt = 0;
    while (x % 10 == 0 && x > 0)
    {
        cnt++;
        x /= 10;
    }
    return cnt;
}

// Reversal of number
ll reverseNum(ll x)
{
    ll res = 0;
    while (x > 0)
    {
        res = res * 10 + x % 10;
        x /= 10;
    }
    return res;
}

// Comparator for sorting by trailing zero then value
bool cmp(pair<ll, int> a, pair<ll, int> b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> v(n);
        for (ll i = 0; i < n; i++)
            cin >> v[i];

        // Create vector of (value, trailing_zeros)
        vector<pair<ll, int>> temp;
        for (ll i = 0; i < n; i++)
        {
            temp.push_back({v[i], trailingZeros(v[i])});
        }

        sort(temp.begin(), temp.end(), cmp);

        // Anna minimizes by reversing from back (remove trailing zeros)
        ll ans = 0;
        ll i = n - 1;
        bool turn = true;

        while (i >= 0)
        {
            if (turn)
            {
                // Anna's turn - remove trailing zeros from end
               // ans -= temp[i].second;

               string str=to_string(temp[i].first);
                ans=ans+str.size()-temp[i].second;
                i--;
            }
            else
            {
                // Sasha's turn - concatenate next two biggest reversed numbers
                     string str=to_string(temp[i].first);
                     ans=ans+str.size();
                     i--;
            }
            turn = !turn;
        }

        if (ans >= m + 1)
            cout << "Sasha" << endl;
        else
            cout << "Anna" << endl;
    }
    return 0;
}
