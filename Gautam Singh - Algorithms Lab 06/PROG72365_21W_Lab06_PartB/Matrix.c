#include "Matrix.h"

/*
 * MultiplyAx()
 * Compute the product of y = Ax in an m x n matrix and x is an n x 1 vector
 * y is the output which will be an m x 1 vector
 * E.g.	(a b c d) (u) = (au + bv + cw + dz) = (r1)
 *		(e f g h) (v) = (eu + fv + gw + hz) = (r2)
 *		(i j k l) (w) = (iu + jv + kw + lz) = (r3)
 *				  (z)
 *          A      x                           y
 */

void  MultiplyAx(float* A, int mRows, int nCols, float* x, float* y) {
	//row is counter for rows in matrix A
	for (int row = 0; row < mRows; row++) {
		y[row] = 0; //initialize
		for (int col = 0; col < nCols; col++) {
			y[row] += A[(row * nCols) + col] * x[col]; // 0 * 0  + 1= 0,  1 *4 + 0 = 4,  2 * 4 + 0 = 8
		}
	}
}
