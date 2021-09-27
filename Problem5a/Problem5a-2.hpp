#include "Problem5a-1.hpp"

void jacobi_eigensolver(mat A, double eps, vec& eigenvalues, mat& eigenvectors, const int maxiter, int& iterations, bool& converged) {
	
	int N = A.n_rows;
	
	mat R = eye(N, N);

	int k;
	int l;
	
	double value = max_offdiag_symmetric(A, k, l);

	iterations = 0;

	while(value > eps && iterations < maxiter) {
		
		iterations++;

		jacobi_rotate(A, R, k, l);

		value = max_offdiag_symmetric(A, k, l);

	}

	if (iterations < maxiter) {

		converged = true;
	}
	else{
		
		converged = false;

	}

	eigenvalues = diagvec(A);

	R = normalise(R);


	uvec ind = sort_index(eigenvalues);

	eigenvalues = sort(eigenvalues);


	for(int i=0; i < N; i++){

		eigenvectors.shed_col(i);

		eigenvectors.insert_cols(i, R.col(ind(i)));

	}


	//eigenvectors.shed_col(N-1);

}
