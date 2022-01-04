
void  MultiplyHx(int* A, int mRows, int nCols, int* x, int* y) {
	//row is counter for rows in matrix A
	for (int row = 0; row < mRows; row++) {
		y[row] = 0; //initialize
		for (int col = 0; col < nCols; col++) {
			y[row] += A[(row * nCols) + col] * x[col]; // 0 * 0  + 1= 0,  1 *4 + 0 = 4,  2 * 4 + 0 = 8
		}
		y[row] %= 2;
	}
	return;
}

void showEncode(int* H, int* p, int* r) {
	for (int row = 0; row < 7; row++) {
		printf("[");
		for (int col = 0; col < 4; col++) {
			printf("%d", H[(row * 4) + col]);
		}
		if (row < 4) {
			printf("] [ %d ]", p[row]);
		}
		else {
			printf("]       ");
		}
		//set a single = sign for the equation
		char charVal = ' ';
		if (row == 0) {
			charVal = '=';
		}
		//print r and end the row
		print(" %c [ %d ]\n", charVal, r[row]);
	}
	return;
}

void showDecode(int* H, int* r, int* s) {
	for (int row = 0; row < 7; row++) {
		//start row of printing
		//print the H matrix
		if (row < 3) {
			printf("[");
			for (int col = 0; col < 7; col++) {
				printf("%d", H[(row * 7) + col]);
			}
			printf("]");
		}
		else {
			printf("                  ");
		}
		//Print the r matrix
		printf(" [ %d ]", r[row]);
		if (row >= 3) {
			printf("\n");
		}

		//set a single = at the top
		char charVal = ' ';
		if (row == 0) {
			charVal = "=";
		}
		//print the s matrix and end the row
		if (row < 3) {
			printf(" %c [ %d ]\n", charVal, s[row]);
		}
	}
	return;
}