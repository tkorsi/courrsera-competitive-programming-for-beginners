#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, INT64_MAX));
    vector<int64_t> min_cols(m + 1, INT64_MAX);
    vector<pair<int, int>> min_cols_cell(m + 1, {1, 1});
    vector<vector<pair<int, int>>> parents(n + 1, vector<pair<int, int>>(m + 1, {1, 1}));

    for (int i = 1; i <= n; ++i) {
        int64_t min_row = INT64_MAX;
        pair<int, int> min_row_cell = {1, 1};
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                cin >> dp[i][j];
                min_row = dp[i][j];
                min_cols[j] = dp[i][j];
                continue;
            }
            int64_t val; cin >> val;
            int64_t z = min(min_row, min_cols[j]);
            if (min_row > min_cols[j]) {
                parents[i][j] = min_cols_cell[j];
            } else {
                parents[i][j] = min_row_cell;
            }
            dp[i][j] = z + val;
            if (dp[i][j] < min_row) {
                min_row = dp[i][j];
                min_row_cell = {i, j};
            }
            
            if (min_cols[j] > dp[i][j]) {
                min_cols[j] = dp[i][j];
                min_cols_cell[j] = {i, j};
            }
        }
    }
    vector<pair<int, int>> res;
    int64_t ans = dp[n][m];
    res.push_back({n, m});
    while (n != 1 || m != 1)
    {
        auto p = parents[n][m];
        n = p.first;
        m = p.second;
        res.push_back({n, m});
    }
    
    cout << ans << " " << res.size() << "\n";
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i].first << " " << res[i].second << "\n";
    }
}