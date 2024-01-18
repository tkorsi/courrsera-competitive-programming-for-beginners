#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector <int>> adjM(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        string inp; cin >> inp;
        for (int j = 0; j < n; ++j) {
            adjM[i][j] = inp[j] == '1' ? 1 : 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        vector<int> edges;
        for (int j = 0; j < n; ++j) {
            if (adjM[i][j] == 1) {
                edges.push_back(j);
            }
        }
        cout << edges.size() << " ";
        for (auto el : edges) {
            cout << el + 1 << " ";
        }
        cout << '\n';
    }
}
