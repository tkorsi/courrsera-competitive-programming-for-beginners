#include <iostream> 
#include <vector> 

using namespace std;

int main() {
    int S, N; cin >> S >> N;
    vector<int> w(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        cin >> w[i];
    }
    
    vector<vector<int>> dp(N + 1, vector<int>(S + 1, 0));
    dp[0][0] = 1;
    for(int i = 1; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (w[i] <= j) {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - w[i]];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int idx = -1;
    vector<int> res;
    for (int i = S; i >= 0; --i) {
        if (dp[N][i] == 1) {
            idx = i;
            cout << idx << " ";
            break;
        }
    }
    while (idx > 0)
    {
        if (dp[N - 1][idx] == 1) {
            N -= 1;
            continue;
        } else {
            res.push_back(N);
            idx -= w[N];
        }
    }
    cout << res.size();
    cout << '\n';
    for (int i = (int)res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
    }
}