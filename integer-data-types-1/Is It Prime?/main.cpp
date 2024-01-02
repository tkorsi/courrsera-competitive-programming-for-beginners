#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 2; (int64_t)i*i <= N; ++i) {
        if (N % i == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
    cout << 1 << '\n';
    return 0;
}