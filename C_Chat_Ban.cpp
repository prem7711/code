// header files and namespaces
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define fast                      \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

int main()
{
    fast;
    ll t;
    cin >> t;
    while (t--)
    {
        ll k, x;
        cin >> k >> x;

        ll full_sum = k * k;
        if (x >= full_sum)
        {
            cout << 2 * k - 1 << '\n';
            continue;
        }

        ll first_half_sum = (k * (k + 1)) / 2;

        if (x <= first_half_sum)
        {
            ll l = 1, r = k, ans = k;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll sum = (mid * (mid + 1)) / 2;
                if (sum >= x)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cout << ans << '\n';
        }
        else
        {
            x -= first_half_sum;
            ll l = 1, r = k - 1, ans = 0;
            while (l <= r)
            {
                ll mid = (l + r) / 2;
                ll total = (k - 1) * k / 2;
                ll removed = (k - mid - 1) * (k - mid) / 2;
                ll usable = total - removed;

                if (usable >= x)
                {
                    ans = mid;
                    r = mid - 1;
                }
                else
                {
                    l = mid + 1;
                }
            }
            cout << k + ans << '\n';
        }
    }
    return 0;
}
