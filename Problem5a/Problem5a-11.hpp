#include "Problem4a.hpp"

void jacobi_rotate(mat& A, mat& R, int& k, int& l) {

    int N = A.n_rows;
    
    double value = max_offdiag_symmetric(A, k, l);

    double c, s;

    if (A(k,l) != 0.0) {
        
        double tau = (A(l, l) - A(k, k)) / (2. * A(k, l));
        double t;
        
        if (tau > 0) {

        t = -tau + sqrt(1. + tau * tau);

        }
        else {

        t = -tau - sqrt(1. + tau * tau);
        
        }
        
        c = 1. / sqrt(1. + t * t);
        
        s = c * t;
        }
    else {
        c = 1.0;
        s = 0.0;
    }


    double akk;

    double all;

    akk = A(k, k) * c * c - 2. * A(k, l) * c * s + A(l, l) * s * s;

    all = A(l, l) * c * c + 2. * A(k, l) * c * s + A(k, k) * s * s;

    A(k,k) = akk;

    A(l,l) = all;

    A(k, l) = 0.;

    A(l, k) = 0.;



    for (int j = 0; j < N; j++) {

        if (j != k && j != l) {

            double ak, al;

            ak = A(j,k);
            al = A(j, l);
            A(j,k) = c * ak - s * al;
            A(k,j) = A(j,k);
            A(j,l) = c * al + s * ak;
            A(l,j) = A(j,l);
        }
        
        double rk, rl;
        
        rk = R(j, k);
        rl = R(j,l);
        R(j,k) = c * rk - s * rl;
        R(j,l) = c * rl + s * rk;
    }
    
}
