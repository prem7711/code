#include <bits/stdc++.h>
using namespace std;

bool f1(int mid, vector<int> &freq, int n) {
    int required = 0;
    if (mid == 0) {
        return false;
    }

    for (int i : freq) {
        if (i > 0) {
            required += (i + mid - 1) / mid; 
        }
    }

    return required <= n;
}

int findMinimumX(string &s, int n) {
    vector<int> freq(26, 0);
    for (char c : s) {
        freq[c - 'a']++;
    }

    int left = 0, right = s.length(), mid = 0, ans = s.length();
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (f1(mid, freq, n)) {
            ans = min(ans, mid);
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
  
    int n;
    cin >> n;
    string s;
    cin >> s;
    
    cout << findMinimumX(s, n) << "\n";
    
    return 0;
}
