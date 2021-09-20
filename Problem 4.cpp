#include <armadillo>
#include <iostream>
#include <cmath>
#include <fstream>

using namespace arma;
using namespace std;


double max_offdiag_symmetric(const arma::mat& A, int& k, int& l)
{
	if (A.is_square() == true) {

		int n = A.n_rows;

		if (n > 1) {

			double maxval = 0;

			for (int i = 0; i < n; i++) {

				for (int j = 1; i < n; i++) {

					if (i < j && abs(A(i, j) > maxval)) {
						
						k = i;
						l = j;
						maxval = A(i, j);

					}

				}

			}

			return(maxval);

		}

		
		else {

			cout << "no funciona salu2";

		}

	}

	else {

		cout << "no funciona salu2";

	}

}

int main() {

	int n = 4;

	mat A = eye(n, n);

	vec v(n, fill::zeros);

	v << 1 << 2 << 3;

	v = A.diag(1);

	int k, l;

	double value = max_offdiag_symmetric( A , k,  l);

	cout << k << " " << l << " " << value;

	return 0;

}
