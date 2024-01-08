#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, INT32_MAX));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT32_MAX));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            int val = min(dp[i - 1][j - 1], dp[i][j - 1]);
            dp[i][j] = min(dp[i - 1][j], val) + a[i][j];
        }
    }

    vector<pair<int, int>> res;
    for (int i = n, j = m;;) {
        res.push_back({i, j});
        if (i == 1 && j == 1) {
            break;
        }
        if (dp[i][j] == dp[i - 1][j] + a[i][j]) {
            i -= 1;
            continue;
        }
        if (dp[i][j] == dp[i][j - 1] + a[i][j]) {
            j -= 1;
            continue;
        }
        i -= 1;
        j -= 1;
    }
    cout << dp[n][m] << " " << res.size() << "\n";
    for (int i = (int)res.size() - 1; i >= 0; --i) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
}