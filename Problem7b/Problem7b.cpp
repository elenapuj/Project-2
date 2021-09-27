#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Problem5a-2.hpp"

using namespace arma;
using namespace std;

int main(){

        int n = 100;
        int N = n-1;

        double eps = pow(10, -8);

        //We define h , which is the stepsize

        double h = 1. / (N + 1);

        //Now we define the matrix A full of zeros

        mat A(N, N, fill::zeros);

        //We introduce vectors a and d

        vec a = vec(N).fill(-1. / (pow(h, 2)));
        vec d = vec(N).fill(2. / (pow(h, 2)));

        //The following loop allows to fill correctly the matrix A defined before

        for (int i = 0; i < N - 1; i++) {
                A(i, i) = d(i);
                A(i, i + 1) = a(i);
                A(i + 1, i) = a(i);

        }

        //The last element of the matrix A needs to be created apart becuase the loop goes until N-2
 
        A(N - 1, N - 1) = d(N - 1);


        //We define a vector that contains the eigenvalues and a matrix that contains the eigenvectors

        vec eigenvalues(N);
        mat eigenvectors(N,N);

        int maxiter = 10000;
        int iterations;
        bool converged;

        //With the following function we get the eigevalues and eigenvectors

        jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);

        //We create a .txt file that stores the matrix that contains the eigenvectors

        ofstream ofile;
        ofile.open("Problem7b.txt");
        ofile << scientific;
        ofile << eigenvectors << endl;
        ofile.close();
        return 0;

}
