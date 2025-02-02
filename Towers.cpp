#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> cubes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cubes[i];
    }

    vector<int> towers;

    for (int i = 0; i < n; i++)
    {
        auto it = upper_bound(towers.begin(), towers.end(), cubes[i]);
        if (it == towers.end())
        {
            towers.push_back(cubes[i]);
        }
        else
        {
            *it = cubes[i];
        }
    }

    cout << towers.size() << endl;

    return 0;
}
