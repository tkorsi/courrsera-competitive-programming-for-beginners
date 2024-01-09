#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<vector<int64_t>> dp(n + 1, vector<int64_t>(m + 1, INT64_MAX));
    vector<int64_t> min_cols(m + 1, INT64_MAX);
    vector<pair<int, int>> min_cols_cell(m + 1, {1, 1});

    vector<int64_t> min_diags(1e6 + m + 1, INT64_MAX);
    vector<pair<int, int>> min_diags_cell(1e6 + m + 1, {1, 1});

    vector<vector<pair<int, int>>> parents(n + 1, vector<pair<int, int>>(m + 1, {1, 1}));

    for (int i = 1; i <= n; ++i) {
        int64_t min_row = INT64_MAX;
        pair<int, int> min_row_cell = {1, 1};
        for (int j = 1; j <= m; ++j) {
            if (i == 1 && j == 1) {
                cin >> dp[i][j];
                min_row = dp[i][j];
                min_cols[j] = dp[i][j];
                min_diags[0] = dp[i][j]; 
                continue;
            }

            int64_t val; cin >> val;
            int64_t diag_idx;
            if (i == j) {
                diag_idx = 0;
            } else if (i > j) {
                diag_idx = i - j;
            } else {
                diag_idx = 1e6 + j - i;
            }

            int64_t min_diag = min_diags[diag_idx];
            int64_t dir;

            if (min_row < min_cols[j]) {
                if (min_row < min_diag) {
                    parents[i][j] = min_row_cell;
                    dir = min_row;
                } else {
                    parents[i][j] = min_diags_cell[diag_idx];
                    dir = min_diag;
                }
            } else {
                if (min_cols[j] < min_diag) {
                    parents[i][j] = min_cols_cell[j];
                    dir = min_cols[j];
                } else {
                    parents[i][j] = min_diags_cell[diag_idx];
                    dir = min_diag;
                }
            }

            dp[i][j] = dir + val;

            if (dp[i][j] < min_row) {
                min_row = dp[i][j];
                min_row_cell = {i, j};
            }
            
            if (min_cols[j] > dp[i][j]) {
                min_cols[j] = dp[i][j];
                min_cols_cell[j] = {i, j};
            }

            if (dp[i][j] < min_diag) {
                min_diags[diag_idx] = dp[i][j];
                min_diags_cell[diag_idx] = {i, j};
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