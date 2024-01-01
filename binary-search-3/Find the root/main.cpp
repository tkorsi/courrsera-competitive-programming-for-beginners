#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const long double EPS = 1e-15;

long double f(long double x1, long double x2, long double x3, long double x4, long double x5, long double x6, long double x) {
    x1 *= x * x * x * x * x;
    x2 *= x * x * x * x ;
    x3 *= x * x * x;
    x4 *= x * x;
    x5 *= x;
    return x1 + x2 + x3 + x4 + x5 + x6;
}

int main() {
    int n;
    cin >> n;
    vector<long double> vals(6, 0.0);
    for (int i = 5 - n; i < 6; ++i) {
        cin >> vals[i];
    }
    long double l = -1e6;
    long double r = 1e6;
    while (r - l > EPS) {
        long double mid = (l + r) / 2;
        long double func_value = f(vals[0], vals[1], vals[2], vals[3], vals[4], vals[5], mid);
        if (func_value == 0.0) {
            break;
        }
        if (func_value < 0.0) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << std::setprecision(15) <<  (l + r) / 2 << '\n';
    return 0;
}