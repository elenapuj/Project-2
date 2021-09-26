#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include "Problem5a-2.hpp"

using namespace arma;
using namespace std;

int main(){

        int n = 10;
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

        //The last element of the matrix A needs to be created apart becuase the >
        A(N - 1, N - 1) = d(N - 1);

        vec eigenvalues;
        mat eigenvectors;
        int maxiter = 10000;
        int iterations;
        bool converged;

        jacobi_eigensolver(A, eps, eigenvalues, eigenvectors, maxiter, iterations>
        eigenvalues.print("Eigenvalues:");
        eigenvectors.print("Eigenvectors:");

//      ofstream ofile;
//      ofile.open("Problem7.txt");
//      ofile << scientific;

        mat B(N, N, fill::zeros);

//      B.insert_cols(0, eigenvalues);
//      B.insert_cols(1, eigenvectors);

        for (int i = 0; i < N; i++){
                B.col(0) = shift(eigenvalues, i);
                B.cols(i+1) = shift(eigenvectors,i);
//              B(i,0) = eigenvalues(i);
//              B(i,i+1) = eigenvectors(i,i
        }
        B.print("B:");
//                      ofile << eigenvalues << "          " << eigenvectors << e>//              }
//      }
//      ofile << eigenvalues << "               " << eigenvectors << endl;
        
                           return 0;
}
          
