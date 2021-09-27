#include "Problem4a.hpp"
int main() {

    //Matrix A is created (declared) and defined
    
    mat A;
    A << 1. << 0. << 0. << 0.5 << endr
        << 0. << 1. << -0.7 << 0. << endr
        << 0. << -0.7 << 1. << 0. << endr
        << 0.5 << 0. << 0. << 1. << endr;
    
    //k and l index are declared
    
    int k, l;
    
    //The maximum value we are loking for is obteined and printed with it's correspondent index
    
    double value = max_offdiag_symmetric(A, k, l);

    cout << k << " " << l << " " << value;

    return 0;

}
