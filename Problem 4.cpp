#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;


//First, we create a function that gets the maximum value that we are looking for

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l){

   //We define maxval, where we will store this maximum value. We first assign 0 to this value so we are able to compare it later with the el>

   double maxval = 0;


   //With this two first if's we check if the matrix is square and bigger than just one number

   if (A.is_square() == true) {

        //Here we store the dimension of the matrix so we are able to use it in an easier way later

        int n = A.n_rows;

        if (n > 1) {

                //Then, if A satisfy both of the conditions mentioned above, we

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
  
