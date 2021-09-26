#define _USE_MATH_DEFINES

#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace arma;
using namespace std;


//This function allows to check if the eigenvalues and eigenvectors from Armadillo agrees with the analytical result for N = 6

void check_values(mat& aeigvec, vec& aeigval, vec a, vec d, const int N, const vec eigval, const mat eigvec_normalised){


        //With the two following loops we calculate the eigenvectors and a eigenvalues analitically

        for(int i = 0; i < N; i++){

                aeigval(i) = d(i) + 2.*a(i)*cos((i+1.)*M_PI/(N+1.));

        }


        //We define a transpose matrix of the matrix that contains the eigenvectors

        for(int i = 0; i < N; i++){

                for (int j = 0; j < N; j++){

                        aeigvec(j,i) = sin((j+1.)*(i+1.)*M_PI/(N+1.));

                }
        }


        //We print in screen the analytical results

        aeigvec.print("Analytical eigenvectors:");
        aeigval.print("Analytical eigenvalues:");


 	//We define this two booleans

        bool val;
        bool vec;
	double eps = pow(10, -8);


        //With these loops we check if the eigenvalues and eigenvectors from Armadillo matches the ones obtained analitically

	for (int i = 0; i < N; i++){

                for (int j = 0; j < N; j++){

                        //This value will allow us to normalise the vectors obtained analitically

                        double c = 1. / sqrt(pow(aeigvec(j,0),2)+pow(aeigvec(j,1),2)+pow(aeigvec(j,2),2)+pow(aeigvec(j,3),2)+pow(aeigvec(j,4),2));

                        //If the eigenvalues matches, b will acquire the value 1, and if they don't b will be 0

                        if (abs(eigval(i) - aeigval(i)) < eps){

                                val = true;

                        }

                        else{

                                val = false;

				break;

                        }

                        //If the eigenvectors matches, l will acquire the value 1, and if they don't l will be 0

                        if (abs(eigvec_normalised(j,i) - aeigvec(j,i)*c) < eps){

                                vec = true;

                        }

                        else{

                                vec = false;

				break;

                        }
                }
        }


        //Finally if val = true and vec = true, it will be printed in screen a message that confirms that the eigenvalues and eigenvectors match

	if (val==true && vec==true){

                cout << "The eigenvalues and eigenvectors from Armadillo agrees with the analytical results for N = 6" << endl;

        }

        else{

                cout << "The eigenvalues and eigenvectors from Armadillo does not agree with the analytical results for N = 6" << endl;

        }


}

