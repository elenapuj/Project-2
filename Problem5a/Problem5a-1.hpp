#include "Problem4a.hpp"

// A function is created to do the Jacobi rotation

void jacobi_rotate(mat& A, mat& R, int& k, int& l) {

    int N = A.n_rows;
    
    //The maximum value we are looking for is obtained
    
    double value = max_offdiag_symmetric(A, k, l);

    double c, s;

    if (A(k,l) != 0.0) {
        
        //Tau is defined and Tan(θ) is declared; it will be defined in the following if loop
        
        double tau = (A(l, l) - A(k, k)) / (2. * A(k, l));
        double t;
        
        if (tau > 0) {

        t = -tau + sqrt(1. + tau * tau);

        }
        else {

        t = -tau - sqrt(1. + tau * tau);
        
        }
        
        //Cos(θ) and Sin(θ) are defined as a function of Tan(θ)
        
        c = 1. / sqrt(1. + t * t);
        
        s = c * t;
        }
    else {
        c = 1.0;
        s = 0.0;
    }

    
    //Elements A(l, l) and A(k, k) are stored in memory
    
    double akk;

    double all;

    akk = A(k, k) * c * c - 2. * A(k, l) * c * s + A(l, l) * s * s;

    all = A(l, l) * c * c + 2. * A(k, l) * c * s + A(k, k) * s * s;
    
    //Elements A(k, k), A(l, l), A(k, l) and A(l, k) are defined
    
    A(k,k) = akk;

    A(l,l) = all;

    A(k, l) = 0.;

    A(l, k) = 0.;



    for (int j = 0; j < N; j++) {

        if (j != k && j != l) {
            
            //Every element (except for the ones in the diagonal) of A is redefined 
            
            double ak, al;

            ak = A(j,k);
            al = A(j, l);
            A(j,k) = c * ak - s * al;
            A(k,j) = A(j,k);
            A(j,l) = c * al + s * ak;
            A(l,j) = A(j,l);
        }
        
        //Every element of matrix R is defined
        
        double rk, rl;
        
        rk = R(j, k);
        rl = R(j,l);
        R(j,k) = c * rk - s * rl;
        R(j,l) = c * rl + s * rk;
    }
    
}
