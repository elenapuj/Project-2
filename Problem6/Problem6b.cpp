#include "Problem5a-2.hpp"

int main(){
    
    double eps = pow(10, -8);
    
    //We can use ofstream ofile to create a .txt file to save the number of iterations and the size of the matrix

    ofstream ofile;
    ofile.open("iterations_densematrix.txt");
    ofile << "N     iterations" << endl;
    ofile << scientific;

    
    for (int N = 2; N <= 100; N++) {

        //Now we define the matrix A full of random values

        mat Ap(N, N, fill::randn);
        
        //But symmetric

        mat A = symmatu(Ap);
        
        //We define some variables we need for the jacobi_eigensolver function

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

