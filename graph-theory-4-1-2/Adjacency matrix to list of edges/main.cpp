#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<string> mat(n);
    for (int i = 0; i < n; ++i) {
        cin >> mat[i];
    }

    vector<pair<int, int>> res;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (mat[i][j] == '1') {
                pair<int, int> edge = {i +1, j + 1};
                res.push_back(edge);
            }
        }
    }

    cout << res.size() << '\n';
    for (auto p : res) {
        cout << p.first << " " << p.second << '\n';
    }
}