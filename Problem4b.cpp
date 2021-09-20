#include "Problem4a.hpp"
int main() {

    mat A;
    A << 1. << 0. << 0. << 0.5 << endr
        << 0. << 1. << -0.7 << 0. << endr
        << 0. << -0.7 << 1. << 0. << endr
        << 0.5 << 0. << 0. << 1. << endr;

    int k, l;

    double value = max_offdiag_symmetric(A, k, l);

    cout << k << " " << l << " " << value;

    return 0;

}