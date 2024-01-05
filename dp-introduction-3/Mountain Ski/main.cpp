#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> a(100, vector<int>(100));
vector<vector<vector<int>>> dp(100, vector<vector<int>>(100, vector<int>(100, INT32_MAX)));

int f(int n, int s = 0, int l = 0) {
    if (n == 0) {
        return a[l][s];
    }
    if (dp[n][s][l] != INT32_MAX) {
        return dp[n][s][l];
    }
    int val = max(f(n - 1, s, l + 1), f(n - 1, s + 1, l + 1)) + a[l][s];
    dp[n][s][l] = val;
    return val;
}

int main() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i + 1; ++j) {
            cin >> a[i][j];
        }
    }
    cout << f(n - 1) << '\n';
}