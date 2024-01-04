#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    for (int i = 4; i <= n; ++i) {
        if (i % 6 == 0) {
            int m = min(dp[i / 3], dp[i / 2]);
            dp[i] = min(dp[i - 1], m) + 1;
            continue;
        }
        if (i % 3 == 0) {
            dp[i] = min(dp[i / 3], dp[i - 1]) + 1;
            continue;
        }
        if (i % 2 == 0) {
            dp[i] = min(dp[i / 2], dp[i - 1]) + 1;
            continue;
        }
        dp[i] = dp[i - 1] + 1;
    }

    cout << dp[n] << '\n';
}