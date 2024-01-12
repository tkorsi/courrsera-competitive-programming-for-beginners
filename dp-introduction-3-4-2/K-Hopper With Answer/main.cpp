#include <iostream> 
#include <vector> 
#include <deque>
#include <algorithm>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> dp(n + 1, UINT64_MAX);
    vector<int> prev(n + 1);
    deque<int> q;
    
    dp[0] = 0;
    q.push_back(0);

    for (int i = 1; i <= n; ++i) {
        while (!q.empty() && q.front() < i - k) {
            q.pop_front();
        }

        dp[i] = dp[q.front()] + a[i - 1];
        prev[i] = q.front();

        while (!q.empty() && dp[i] <= dp[q.back()]) {
            q.pop_back();
        }

        q.push_back(i);
    }

    vector<int> path;
    for (int i = n; i > 0; i = prev[i]) {
        path.push_back(i);
        if (i == 0) break;
    }
    reverse(path.begin(), path.end());

    cout << dp[n] << " " << path.size() << '\n';
    for (auto a : path) {
        cout << a << " ";
    }
    cout << '\n';
}