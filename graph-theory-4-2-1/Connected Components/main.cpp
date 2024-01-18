#include <iostream>
#include <vector>

using namespace std;

vector<int> connected;
vector<int> visited;
vector<vector<int>> graph;

void dfs(int i, int c) {
    connected[i] = c;
    visited[i] = true;
    for (int v : graph[i]) {
        if (!visited[v]) {
            dfs(v, c);
        }
    }
}

int main() {
    int n, m; cin >> n >> m;
    connected.resize(n + 1, -1);
    visited.resize(n + 1);
    graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int count = 0;
    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            ++count;
            dfs(i, count);
        }
    }
    cout << count << '\n';
    for (int i = 1; i <= n; ++i) {
        cout << connected[i] << " ";
    }
}