#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }

    ordered_set window;
    vector<int> medians;

    // Insert the first k-1 elements into the ordered set
    for (int i = 0; i < k - 1; ++i)
    {
        window.insert({nums[i], i});
    }

    // Process each element from k-1 onwards
    for (int i = k - 1; i < n; ++i)
    {
        // Insert the current element
        window.insert({nums[i], i});

        // Find the median
        auto median_it = window.find_by_order((k - 1) / 2);
        medians.push_back(median_it->first);

        // Remove the element that is sliding out of the window
        window.erase({nums[i - k + 1], i - k + 1});
    }
    int n1 = medians.size();
    for (int i = 0; i < n1; i++)
    {
        cout << medians[i] << " ";
    }
    cout << endl;

    return 0;
}
