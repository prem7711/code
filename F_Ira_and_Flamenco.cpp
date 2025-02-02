#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

ll mod_mult(ll a, ll b, ll mod)
{
    return (a % mod) * (b % mod) % mod;
}

ll mod_exp(ll base, ll exp, ll mod)
{
    ll result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
        {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

ll mod_inv(ll a, ll mod)
{
    return mod_exp(a, mod - 2, mod);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;

    while (t--)
    {
        ll n, m;
        cin >> n >> m;

        vector<ll> levels(n);
        map<ll, ll> freq;
        for (ll i = 0; i < n; i++)
        {
            cin >> levels[i];
            freq[levels[i]]++;
        }

        vector<ll> unique_levels;
        for (auto &p : freq)
        {
            unique_levels.push_back(p.first);
        }

        ll ans = 0;
        int unique_size = unique_levels.size();
        int i = 0, j = 0;

        ll product = 1;
        while (j < unique_size)
        {
            product = mod_mult(product, freq[unique_levels[j]], MOD);

            if (j - i + 1 == m)
            {
                if (unique_levels[j] - unique_levels[i] < m)
                {
                    ans = (ans + product) % MOD;
                }
                product = mod_mult(product, mod_inv(freq[unique_levels[i]], MOD), MOD);
                i++;
            }
            j++;
        }

        cout << ans << '\n';
    }

    return 0;
}
