#include "Problem5a-1.hpp"

//A function is created to obtain the eigenvalues and the eigenvectors using Jacobi's rotation method.

void jacobi_eigensolver(mat A, double eps, vec& eigenvalues, mat& eigenvectors, const int maxiter, int& iterations, bool& converged) {
	
	int N = A.n_rows;
	
	//Matrix R is defined as the Identity Matrix
	
	mat R = eye(N, N);

	int k;
	int l;
	
	//The maximum value we are looking for is obtained
	
	double value = max_offdiag_symmetric(A, k, l);
	
	//An interation meter is declared and set up to 0
	
	iterations = 0;
	
	//Jacobi's method is used while the maximum value looked is bigger than the epsilon given, and while the number of iterations has not surpassed the maximum number allowed
	
	while(value > eps && iterations < maxiter) {
		
		iterations++;

		jacobi_rotate(A, R, k, l);

		value = max_offdiag_symmetric(A, k, l);

	}
	
	//convergence is defined as true is the previous loop is ended because the maximum value is smaller than the epsilon given
	
	if (iterations < maxiter) {

		converged = true;
	}
	else{
		
		converged = false;

	}
	
	//Once it has been done, the eigenvalues are the elements of the diagonal of matrix A
	
	eigenvalues = diagvec(A);
	
	//Eigenvalues are normalized
	
	R = normalise(R);
	
	//Eigenvalues are sorted from smallest to biggest.

	uvec ind = sort_index(eigenvalues);

	eigenvalues = sort(eigenvalues);

	//Eigenvecctors are sorted as their correspondent eigenvalue
	
	for(int i=0; i < N; i++){

		eigenvectors.shed_col(i);

		eigenvectors.insert_cols(i, R.col(ind(i)));

	}

}
