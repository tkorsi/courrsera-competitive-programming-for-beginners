#include <iostream>

using namespace std;

int Primes[1000010];

int min_prime(int N) {
    for (int i = 2; (int64_t)i*i <= N; ++i) {
        if (N % i == 0) {
            cout << 0 << '\n';
            return 0;
        }
    }
}

int main() {
    int M = 1000010;
    int N;
    cin >> N;
    for (int i = 2; (int64_t)i*i <= M; ++i) {
        if (Primes[i] == 0) {
            for (int j = 2; (int64_t)j*i <= M; ++j) {
                Primes[j*i] = 1;
            }
        }
    }
    int res = 0;
    for (int i = 4; i <= N; ++i) {
        if (Primes[i] == 1) {
            for (int j = 2; j <= N; ++j) {
                if (i % j == 0) {
                    res += j;
                    break;
                }
            }
        }
    }
    cout << res << '\n';
    return 0;
}