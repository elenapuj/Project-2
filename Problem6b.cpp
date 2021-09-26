#include "Problem5a-2.hpp"

int main(){

    double eps = pow(10, -8);

    ofstream ofile;
    ofile.open("iterations_densematrix.txt");
    ofile << "N     iterations" << endl;
    ofile << scientific;

    
    for (int N = 2; N <= 100; N++) {

        //We define h , which is the stepsize

        double h = 1. / (N + 1);

        //Now we define the matrix A full of zeros

        mat Ap(N, N, fill::randn);

        mat A = symmatu(Ap);

        vec eigenvalues;
        mat eigenvectors;
        int maxiter = 100000;
        int iterations;
        bool converged;

        jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations, converged);
                      
        ofile << N << "      " << iterations << endl;
        
    }

    ofile.close();

    cout << "iterations_densematrix.txt has been created" << endl;
    
    return 0;

}

