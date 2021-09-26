#include "Problem4a.hpp"

void jacobi_rotate(mat& A, mat& R, int& k, int& l) {

    int N = A.n_rows;
    
    double value = max_offdiag_symmetric(A, k, l);

    double tau = (A(l, l) - A(k, k)) / (2. * A(k, l));
    
    
    
    
    double t;

    if (tau > 0) {

        t = -tau + sqrt(1. + tau * tau);

    }
    else {

        t = -tau - sqrt(1. + tau * tau);

    }

    double c = 1. / sqrt(1. + tau * tau);

    double s = c * t;

    A(k, k) = A(k, k) * c * c - 2.* A(k, l) * c * s + A(l, l) * s * s;

    A(l, l) = A(l, l) * c * c + 2. * A(k, l) * c * s + A(k, k) * s * s;

    A(k, l) = 0.;

    A(l, k) = 0.;

    for (int j = 0; j < N; j++) {

        if (j != k && j != l) {

            double ak = A(j, k) * c - A(j, l) * s;

            double al = A(j, l) * c + A(j, k) * s;

            A(k, j) = ak;
            A(j, k) = ak;

            A(l, j) = al;
            A(j, l) = al;

        }
        
        double rk = R(j, k) * c - R(j, l) * s;

        double rl = R(j, l) * c + R(j, k) * s;

        R(k, j) = rk;
        R(j, k) = rk;

        R(l, j) = rl;
        R(j, l) = rl;
    }
    
}
