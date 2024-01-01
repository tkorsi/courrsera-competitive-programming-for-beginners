#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t num_ropes(const vector<int64_t>& ropes, int64_t length) {
    int64_t count = 0;
    for (const auto& rope : ropes) {
        count += rope / length;
    }
    return count;
}

int main() {
    int64_t N, K;
    cin >> N >> K;
    vector<int64_t> ropes(N);
    for (int64_t i = 0; i < N; ++i) {
        cin >> ropes[i];
    }

    int64_t l = 1;
    int64_t r = *max_element(ropes.begin(), ropes.end()) + 1;
    int64_t res = 0;

    while (l < r) {
        int64_t mid = l + (r - l) / 2;
        if (num_ropes(ropes, mid) >= K) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid;
        }
    }

    cout << res << '\n';
    return 0;
}