#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    // Create a prefix sum array to count peaks
    vector<int> peaks(n, 0);
    for (int i = 1; i < n - 1; ++i)
    {
        if (a[i] > a[i - 1] && a[i] > a[i + 1])
        {
            peaks[i] = 1;
        }
    }

    vector<int> prefixSum(n, 0);
    for (int i = 1; i < n; ++i)
    {
        prefixSum[i] = prefixSum[i - 1] + peaks[i];
    }

    // Use sliding window to find the maximum number of peaks in any segment of length k
    int maxPeaks = 0, leftIndex = 0;
    for (int i = 0; i <= n - k; ++i)
    {
        int currentPeaks = prefixSum[i + k - 2] - prefixSum[i];
        if (currentPeaks > maxPeaks)
        {
            maxPeaks = currentPeaks;
            leftIndex = i;
        }
    }

    cout << maxPeaks + 1 << " " << leftIndex + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }

    return 0;
}
