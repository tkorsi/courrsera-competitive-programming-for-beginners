#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    int64_t dp[n + 1];
    for (int i = 1; i <= n; ++i) {
        cin >> arr[i];
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for (int i = 2; i <= n; ++i) {
        dp[i] = max(dp[i - 1], dp[i - 2]) + arr[i];
    }
    cout << dp[n] << '\n';
}