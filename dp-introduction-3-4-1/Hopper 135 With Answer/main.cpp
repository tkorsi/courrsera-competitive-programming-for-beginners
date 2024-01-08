#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> dp(n + 1, INT64_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
        int64_t val_one = dp[i - 1];
        int64_t val_two, val_three;
        val_two = val_three = INT64_MIN;
        if (i > 2) {
            val_two = dp[i - 3];
        }
        if (i > 4) {
            val_three = dp[i - 5];
        }
        int64_t m = max(val_two, val_three);
        int64_t cand = max(m, val_one) + a[i - 1];
        if (cand > dp[i]) {
            dp[i] = cand;
        }
    }
    vector<int> res;
    for (int i = n; i >= 1;) {
        res.push_back(i);
        if (dp[i - 1] == dp[i] - a[i - 1]) {
            i -= 1;
            continue;
        }
        if (dp[i - 3] == dp[i] - a[i - 1]) {
            i -= 3;
            continue;
        }
        if (dp[i - 5] == dp[i] - a[i - 1]) {
            i -= 5;
            continue;
        }
    }
    cout << dp[n] << " " << res.size() << '\n';
    for (auto it = res.rbegin(); it != res.rend(); ++it) {
        cout << *it << " ";
    }
}