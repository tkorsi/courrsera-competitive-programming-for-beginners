#include <iostream>

using namespace std;

int64_t copies_time(int64_t time, int x, int y) {
    int64_t fast = min(x, y);
    int64_t ll = max(x, y);
    return (time / fast) + ((time - fast) / ll);
}

int main() {
    int N, x, y;
    cin >> N >> x >> y;
    int64_t l = 0;
    int64_t r = min(x, y) * N;
    while (l + 1 < r) {
        int64_t mid = (l + r) / 2;
        int64_t n = copies_time(mid, x, y);
        if (n >= N) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
}