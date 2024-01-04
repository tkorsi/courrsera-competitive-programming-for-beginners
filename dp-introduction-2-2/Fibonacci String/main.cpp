#include <iostream>
#include <vector>

using namespace std;

vector<int64_t> dp(100, -1);

int64_t f(int i) {
    if (i == 0) {
        return 1;
    }
    if (i == 1) {
        return 2;
    }

    if (dp[i] != -1) {
        return dp[i];
    }

    dp[i] = f(i - 1) + f(i - 2);
    return dp[i];
}

int main() {
    int n; cin >> n;
    cout << f(n) << '\n';
}