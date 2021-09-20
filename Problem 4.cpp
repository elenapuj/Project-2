#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;


double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){

   double maxval = 0;

   if (A.is_square() == true) {

        int n = A.n_rows;

        if (n > 1) {

                for (int i = 0; i < n; i++) {

                        for (int j = 0; j < n; j++) {

                                if (i < j && abs(A(i, j)) > maxval) {

                                        k = i;
                                        l = j;
                                        maxval = abs(A(i, j));

                                }

                        }

                }

        }


        else {

                cout << "no funciona salu2";

        }

   }

   else {

        cout << "no funciona salu2";

   }

   return maxval;

}




int main() {

   mat A;
   A << 1. << 0. << 0. << 0.5 << endr
     << 0. << 1. << -0.7 << 0. << endr
     << 0. << -0.7 << 1. << 0. << endr
     << 0.5 << 0. << 0. << 1. << endr;

   int k, l;

   double value = max_offdiag_symmetric( A , k,  l);

   cout << k << " " << l << " " << value;

   return 0;

}
