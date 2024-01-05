#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }

    dp[1][1] = a[1][1];

    for (int j = 2; j <= m; ++j) {
        dp[1][j] = dp[1][j - 1] + a[1][j];
    }

    for (int i = 2; i <= n; ++i) {
        dp[i][1] = dp[i - 1][1] + a[i][1];
    }

    for (int i = 2; i <= n; ++i) {
        for (int j = 2; j <= m; ++j) {
            int M = min(dp[i - 1][j - 1], dp[i][j - 1]);
            dp[i][j] = min(dp[i - 1][j], M) + a[i][j];
        }
    }
    cout << dp[n][m] << '\n';
}