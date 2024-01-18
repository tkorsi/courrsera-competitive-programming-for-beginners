#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m; cin >> n >> m;
    vector<string> adj(n, string(n, '0'));
    for (int i = 0; i < m; ++i) {
        int u, v; cin >> u >> v;
        adj[u - 1][v - 1] = '1';
        adj[v - 1][u - 1] = '1';
    }

    for (auto s : adj) {
        cout << s << '\n';
    }
}