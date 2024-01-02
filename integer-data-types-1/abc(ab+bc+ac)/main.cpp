#include <iostream>

using namespace std;

int main() {
    uint64_t a, b, c;
    cin >> a >> b >> c;
    uint64_t nom = a * b * c;
    uint64_t denom = a*b + b*c + a*c;
    cout << nom / denom << '\n';
}