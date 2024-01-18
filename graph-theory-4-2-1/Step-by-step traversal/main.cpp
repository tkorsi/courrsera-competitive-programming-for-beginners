#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
vector<int> res;

void dfs(int i) {
    visited[i] = true;
    res.push_back(i);
    for (auto v : graph[i]) {
        if (!visited[v]) {
            dfs(v);
            res.push_back(i);
        }
    }
}

int main() {
    int n, m, v;
    cin >> n >> m >> v;
    graph.resize(n + 1);
    visited.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, y; cin >> x >> y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    dfs(v);
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << ' ';
    }
}