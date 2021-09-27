#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;


//First, we create a function that gets the maximum value that we are looking for

double max_offdiag_symmetric(const arma::mat& A, int& k, int& l) {

    //We define maxval, where we will store this maximum value. We first assign 0 to this value so we are able to compare it later with the el>

    double maxval = 0;


    //With this two first if's we check if the matrix is square and bigger than just one number

    if (A.is_square() == true) {

        //Here we store the dimension of the matrix so we are able to use it in an easier way later

        int N = A.n_rows;

        if (N > 1) {

            //Then, if A satisfy both of the conditions mentioned above, we start comparing each of the elements of the superior triangle>

            for (int i = 0; i < N; i++) {

                for (int j = 0; j < N; j++) {

                    if (i < j && abs(A(i, j)) > maxval) {

                        k = i;
                        l = j;
                        maxval = abs(A(i, j));

                    }

                }

            }

        }


        else {

            cout << "The matrix has to be 2x2 or higher";

        }

    }

    else {

        cout << "The matrix has to be a square matrix";

    }

    //Finally, the function returns the maxval that we found

    return maxval;

}
