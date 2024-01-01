#include <iostream>

using namespace std;

int64_t contains(int64_t size, int64_t h, int64_t w) {
    return (size / w) * (size / h);
}

int main() {
    int64_t w, h, n;
    cin >> w >> h >> n;
    int64_t l = 0;
    int64_t r = max(w, h) * n;
    while (l + 1 < r) {
        int64_t mid = (r + l) / 2;
        int64_t ct = contains(mid, h, w);
        if (ct >= n) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
}