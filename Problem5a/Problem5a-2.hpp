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

	eigenvalues = diagvec(R.t() * A * R);

	eigenvectors = R;
}
© 2021 GitHub, Inc.
