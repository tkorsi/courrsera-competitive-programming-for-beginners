#include <iostream>
#include <vector>

using namespace std;

int n, m;
int mod = 1e9 + 123;
vector<vector<uint64_t>> dp;

bool valid(int i, int j) {
    return 0 < i && i <= n && 0 < j && j <= m;
}

uint64_t f(int i, int j) {
    if (valid(i, j)) {
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        dp[i][j] = ((f(i - 1, j - 2) + f(i + 1, j - 2)) % mod + (f(i - 2, j + 1) + f(i - 2, j - 1)) % mod) % mod;
        return dp[i][j];
    }
    return 0;
}

int main() {
    cin >> n >> m;
    dp = vector<vector<uint64_t>>(n + 1, vector<uint64_t>(m + 1, -1));
    dp[1][1] = 1;
    cout << f(n, m) << '\n';
}