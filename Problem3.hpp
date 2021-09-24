#define _USE_MATH_DEFINES

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;

void check_values(mat& aeigvec, vec& aeigval, const vec a, const vec d, const int N, const vec eigval, const mat eigvec_normalised){

        //vec aeigval = vec(N, fill::zeros);

        for(int i = 0; i < N; i++){

                aeigval(i) = d(i) + 2.*a(i)*cos((i+1)*M_PI/(N+1));

        }

        //mat aeigvec(N, N, fill::zeros);

        for(int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){

                        aeigvec(j,i) = sin((j+1)*(i+1)*M_PI/(N+1));
                }
        }

        mat aeigvect = aeigvec.t();


        aeigvect.print("Analytical eigenvectors:");
        aeigval.print("Analytical eigenvalues:");

        int b;
        int l;
  
        for (int i = 0; i < N; i++){
                for (int j = 0; j < N; j++){

                        double c = 1. / sqrt(pow(aeigvect[j,0],2)+pow(aeigvect[j,1],2)+pow(aeigvect[j,2],2)+pow(aeigvect[j,3],2)+pow(aeigvect[j,4],2));

                        if (round(eigval[i]) == round(aeigval[i])){

                                b = 1;
                        }
                        else{
                                b = 0;
                        }
                        if (round(eigvec_normalised[j,i]) == round(aeigvect[j,i]*c)){
                                l = 1;
                        }
                        else{
                                l = 0;
                        }
                }
        }

        if (b == 1 && l == 1){

                cout << "The eigenvalues and eigenvectors from Armadillo agrees with the analytical results for N = 6" << endl;
        }
        else{
                cout << "The eigenvalues and eigenvectors from Armadillo does not agree with the analytical results for N = 6" << endl;
        }


}
