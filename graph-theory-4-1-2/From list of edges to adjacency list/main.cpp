#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    int num_vert, num_edges;
    cin >> num_vert >> num_edges;
    map<int, set<int>> graph;
    for (int i = 0; i < num_edges; ++i) {
        int n, m;
        cin >> n >> m;
        graph[n].insert(m);
        graph[m].insert(n);
    }
    for (int i = 0; i < num_vert; ++i) {
        set<int> edges = graph[i + 1];
        cout << edges.size() << " ";
        for (auto el : edges) {
            cout << el << " ";
        }
        cout << '\n';
    }
}