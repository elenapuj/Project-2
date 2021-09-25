#define _USE_MATH_DEFINES

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

//This function allows to check if the eigenvalues and eigenvectors from Armadillo agrees with the analytical result for N = 6

void check_values(mat& aeigvec, vec& aeigval, const vec a, const vec d, const int N, const vec eigval, const mat eigvec_normalised){

        //With the two following loops we calculate the eigenvectors and a eigenvalues analitically
        
        for(int i = 0; i < N; i++){
                aeigval(i) = d(i) + 2.*a(i)*cos((i+1)*M_PI/(N+1));
        }
        
        //We define a transpose matrix of the matrix that contains the eigenvectors
        
        mat aeigvect;
        
        for(int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){
                        aeigvect(j,i) = sin((j+1)*(i+1)*M_PI/(N+1));
                }
        }

        mat aeigvec = aeigvect.t();

        //We print in screen the analytical results
        
        aeigvec.print("Analytical eigenvectors:");
        aeigval.print("Analytical eigenvalues:");

        //We define this two values to help us with future calculations
        
        int b;
        int l;
  
        //With this loops we check if the eigenvalues and eigenvectors from Armadillo matches the ones obtained analitically
        
        for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){

                        //This value will allow us to normalise the vectors obtained analitically
                        
                        double c = 1. / sqrt(pow(aeigvec[j,0],2)+pow(aeigvec[j,1],2)+pow(aeigvec[j,2],2)+pow(aeigvect[j,3],2)+pow(aeigvec[j,4],2));

                        //If the eigenvalues matches, b will acquire the value 1, and if they don't b will be 0
                        
                        if (round(eigval[i]) == round(aeigval[i])){
                                b = 1;
                        }
                        
                        else{
                                b = 0;
                        }
                        
                        //If the eigenvectors matches, l will acquire the value 1, and if they don't l will be 0
                        
                        if (round(eigvec_normalised[j,i]) == round(aeigvec[j,i]*c)){
                                l = 1;
                        }
                        else{
                                l = 0;
                        }
                }
        }

        //Finally if b = 1 and l = 1 it will be printed in screen a message that confirms that the eigenvalues and eigenvectors match
        if (b == 1 && l == 1){

                cout << "The eigenvalues and eigenvectors from Armadillo agrees with the analytical results for N = 6" << endl;
        }
        else{
                cout << "The eigenvalues and eigenvectors from Armadillo does not agree with the analytical results for N = 6" << endl;
        }


}
