#include <iostream>
#include <vector>

using namespace std;

int sub(int a, int b, int m) {
    int res = (a - b) % m;
    if (res < 0) {
        res += m;
    }
    return res;
}

int main() {
    int m = 1e9 + 7;
    int n, k; string s;
    cin >> n >> k >> s;
    vector<int> dp(n + 1, 0);
    vector<int> a(n + 1, 0);
    for (int i = 0; i < n; ++i) {
        if (s[i] == '1') {
            a[i] = 0;
        } else {
            a[i] = 1;
        }
    }
    int cur_sum = 1;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        if(i >= k){
            cur_sum = sub(cur_sum, dp[i - k], m);
        }
        if(a[i] == 1){
            dp[i + 1] = cur_sum;
        }
        cur_sum = (cur_sum + dp[i + 1]) % m;
    }
    cout << dp[n];
    return 0;
}