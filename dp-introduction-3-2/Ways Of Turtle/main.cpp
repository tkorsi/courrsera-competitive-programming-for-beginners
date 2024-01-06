#include <iostream>
#include <vector>

using namespace std;

int main() {
    int mod = 1e9 + 9;
    int n, m; cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1));
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> a[i + 1][j + 1];
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=m; ++j) {
            if (a[i][j] == 1) {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = ((dp[i - 1][j] + dp[i - 1][j - 1] ) % mod + dp[i][j - 1]) % mod;
        }
    }

    cout << dp[n][m] << '\n';
}