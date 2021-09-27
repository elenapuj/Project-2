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


	//A matrix with the analytic eigenvectors normalised is created

        mat aeigvecn = normalise(aeigvec);


 	//We define two booleans and a tolerance factor to help us comparing our results

        bool val;
        bool vec;
	double eps = pow(10, -8);


        //With these loops we check if the eigenvalues and eigenvectors from Armadillo matches the ones obtained analitically

	for (int i = 0; i < N; i++){

		//If each of the eingenvalues matches, val will acquire the value true, and if it doesn't val will be false and the loop will be automatically broken

		if (abs(eigval(i) - aeigval(i)) < eps){

			val = true;
			cout << "val=true" << endl;


			//If it matches, we will continue comparing the correspondent eigenvector

			for (int j = 0; j < N; j++){

        	                //If the eigenvectors' components match, vec will acquire the value true, and if they don't vec will be false and both of the loops will be skiped to show that the comparison has failed

                	        if (abs(abs(eigvec_normalised(j,i)) - abs(aeigvecn(j,i))) < eps){

                        	        vec = true;
                                	cout << "vec=true" << endl;

                        	}

                        	else{

                                	vec = false;
                                	cout << "vec=false" << endl;

                                	goto FINAL;

                        	}

                	}


                }

		else{

			val = false;
                        cout << "val=false" << endl;

                        goto FINAL;

		}

        }


        //Finally if val = true and vec = true, it will be printed in screen a message that confirms that the eigenvalues and eigenvectors match

	FINAL:

	if (val==true && vec==true){

                cout << "The eigenvalues and eigenvectors from Armadillo agrees with the analytical results for N = 6" << endl;

        }

        else{

                cout << "The eigenvalues and eigenvectors from Armadillo does not agree with the analytical results for N = 6" << endl;

        }


}

