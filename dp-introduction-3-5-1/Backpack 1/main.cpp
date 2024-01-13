#include <iostream> 

using namespace std;

int main() {
    int S, N; cin >> S >> N;
    int sum;
    for (int i = 0; i < N; ++i) {
        int bar; cin >> bar;
        sum += bar;
    }
    if (sum > S) {
        cout << S << '\n';
    } else {
        cout << sum << '\n';
    }
}