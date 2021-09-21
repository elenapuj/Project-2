#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

double eigen(){

        //First we define the number N, which is the dimension of the matrix A

        int N = 6;

        //We define h , which is the stepsize

        double h = 1. / (N + 1);

        //Now we define the matrix A full of zeros

        mat A(N, N, fill::zeros);

        //We introduce vectors a and b

        vec a = vec(N).fill(-1. / (pow(h, 2)));
        vec d = vec(N).fill(2. / (pow(h, 2)));

        //Now we can finally define matrix A correctly

        for (int i = 0; i < N-1; i++) {
                A(i, i) = d(i);
                A(i, i + 1) = a(i);
                A(i + 1, i) = a(i);
        }

        A(N - 1, N - 1) = d(N - 1);

        vec eigval;
        mat eigvec;

        eig_sym(eigval, eigvec, A);

        mat eigvec_normalised = normalise(eigvec);

        eigvec_normalised.insert_cols(0, eigval);


        return eigvec_normalised;
}

int main(){

        mat B = eigen();

        cout << "Eigenvalues:" << B.col(0) << "Eigenvectors:" << B.shed_row(0) <<>
        return 0;
}
