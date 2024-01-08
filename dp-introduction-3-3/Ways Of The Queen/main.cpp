#include <iostream>
#include <vector>

using namespace std;

long long count_ways(int n, int m) {
    int mod = 1e9 + 7;

    std::vector<std::vector<long long>> dp(n, std::vector<long long>(m, 0));

    std::vector<std::vector<long long>> from_above(n, std::vector<long long>(m, 0));
    std::vector<std::vector<long long>> from_left(n, std::vector<long long>(m, 0));
    std::vector<std::vector<long long>> from_diag(n, std::vector<long long>(m, 0));

    dp[0][0] = 1;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == 0) {
                from_above[i][j] = 0;
            } else {
                from_above[i][j] = (dp[i-1][j] + from_above[i-1][j]) % mod;
            }

            if (j == 0) {
                from_left[i][j] = 0;
            } else {
                from_left[i][j] = (dp[i][j-1] + from_left[i][j-1]) % mod;
            }

            if (i == 0 || j == 0) {
                from_diag[i][j] = 0;
            } else {
                from_diag[i][j] = (dp[i-1][j-1] + from_diag[i-1][j-1]) % mod;
            }

            if (i == 0 && j == 0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = (from_above[i][j] + from_left[i][j] + from_diag[i][j]) % mod;
            }
        }
    }

    return dp[n - 1][m - 1];
}

int main() {
    int n, m; cin >> n >> m;
    std::cout << count_ways(n, m); // For n = 3, m = 3 answer is 22.
    return 0;
}