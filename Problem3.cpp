#define _USE_MATH_DEFINES

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Problem3.hpp"

using namespace arma;
using namespace std;

int main(){

        //First we define the number N, which is the dimension of the matrix A

        int N = 6;

        //We define h , which is the stepsize

        double h = 1. / (N + 1);

        //Now we define the matrix A full of zeros

        mat A(N, N, fill::zeros);

        //We introduce vectors a and d

        vec a = vec(N).fill(-1. / (pow(h, 2)));
        vec d = vec(N).fill(2. / (pow(h, 2)));

        //The following loop allows to fill correctly the matrix A defined before

        for (int i = 0; i < N-1; i++) {

                A(i, i) = d(i);
                A(i, i + 1) = a(i);
                A(i + 1, i) = a(i);
 
        }

        //The last element of the matrix A needs to be created apart becuase the loop goes until N-2

        A(N - 1, N - 1) = d(N - 1);

        //We use Armadillo's arma::eig_sym to get the eigenvalues and eigenvectors of matrix A

        //We define a vector that will contain the eigenvalues and a matrix that will contain the eigenvectors

        vec eigval;
        mat eigvec;

        eig_sym(eigval, eigvec, A);

        //A matrix with the eigenvectors normalised is created

        mat eigvec_normalised = normalise(eigvec);

        //We print in screen matrix A, a vector with the eigenvalues and a matrix with the eigenvectors normalised

        A.print("A:");
        eigval.print("Eigenvalues:");
        eigvec_normalised.print("Eigenvectors:");

        //We define a matrix with the analytical eigenvectors and a vector with the analytical eigenvalues
        
        mat aeigvec;
        vec aeigval;

        //This function allows to check if the eigenvalues and eigenvectors obtained analitically matches the ones obtained with Armadillo
        check_values(aeigvec, aeigval, a, d, N, eigval, eigvec_normalised);

        return 0;

}
