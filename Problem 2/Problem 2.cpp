#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

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

        //Now we define a vector that contains the eigenvalues and a matrix that contains the eigenvectors, both obtained analitically

        vec a_eigval = {9.705, 36.898, 76.193, 119.807, 159.102, 186.295};
        mat a_eigvec;
        a_eigvec << 1. << -1. << 1. << -1. << 1. << -1. << endr
                                << 1.802 << -1.247 << 0.445 << 0.445 << -1.247 << 1.802 << endr
                                << 2.247 << -0.555 << -0.802 << 0.802 <<  0.555 << -2.247 << endr
                                << 2.247 << 0.555 << -0.802 << -0.802 << 0.555 << 2.247 << endr
                                << 1.802 << 1.247 << 0.445 << -0.445 << -1.247 << -1.802 << endr
                                << 1. << 1. << 1. << 1. << 1. << 1. << endr;

        //We print in screen both, the matrix and the vector

        a_eigvec.print("Analytical eigenvectors:");
        a_eigval.print("Analytical eigenvalues:");

        //Finally we have to check that the eigenvalues and eigenvectors from Armadillo agrees with the analytical result for N = 6

        int b;

        //The following loop will check if the eigenvalues from Armadillo matches the ones obtained analitically

        for (int i = 0; i < N; i++){

                //If the eigenvalues matches b will acquire the value 1, and if they don't b will be 0
                
                if(round(eigval[i]) == round(a_eigval[i])){

                        b = 1;

                }

                else{

                        b = 0;

                }
        }

        if(b == 1){

                cout << "The eigenvalues from Armadillo agrees wit the analytical results for N = 6" << endl;
        }

        if (b == 0){

                cout << "The eigenvalues from Armadillo does not agree with the analytical results for N = 6" << endl;
        }

        int l;

        //The followings loops  will check if the eigenvectors from Armadillo matches the ones obtained analitically

        for  (int j = 0; j < N; j++){

                //The value c will allow to normalise the vectors obtained analitically

                double c = 1. / sqrt(pow(a_eigvec[j,0],2)+pow(a_eigvec[j,1],2)+pow(a_eigvec[j,2],2)+pow(a_eigvec[j,3],2)+pow(a_eigvec[j,4],2));

                for (int i = 0; i < N; i++){

                        //If the eigenvectors matches l will acquire the value 1, and if they don't l will be 0

                        if (round(eigvec[j,i]) == round((a_eigvec[j,i])*c)){

                                l = 1;
                        }

                        else{

                                l = 0;
                        }

                }

        }

        if (l == 1){

                cout << "The eigenvectors from Armadillo agrees with the analytical results for N = 6" << endl;

        }

        if (l == 0){

                cout << "The eigenvectors from Armadillo does not agree with the analytical results for N = 6" << endl;
                
        }
}
