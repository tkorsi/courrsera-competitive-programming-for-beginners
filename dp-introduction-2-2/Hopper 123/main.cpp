#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m = 1e9 + 7;
    int n;
    cin >> n;
    vector<int> dp(n + 3, -1);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '1') {
            dp[i + 3] = 0;
        }
    }
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i < n + 3; ++i) {
        if (dp[i] == 0) {
            continue;
        }
        dp[i] = ((dp[i-1] + dp[i-2]) % m + dp[i-3]) % m;
    }
    cout << dp[n + 2] << '\n';
}