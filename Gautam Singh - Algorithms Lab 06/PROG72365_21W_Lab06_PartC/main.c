
#include <stdio.h>
#include<stdlib.h>;
#include "Matrix.h"

int main() {
	int H_Encode[7][4] = { {1, 0, 0, 0}, //given array
		{ 0,1,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 },
		{ 0,1,1,1 },
		{ 1,0,1,1 },
		{ 1,1,0,1 }
	};

	int H_Decode[3][7] = { {0,1,1,1,1,0,0}, //given array
						  {1,0,1,1,0,1,0},
						  {1,1,0,1,0,0,1},
	};

	int p[4] = {1, 0, 1, 1}; //given from slides
	int r[7]; //given from slides
	int s[3];
	//Hamming Encode
	//Encode H = 7x4
	//Decode H = 3x7
	//p = 4x1
	//r = 7x1

	//s = 3x1

	MultiplyHx(H_Encode, 7, 4, p, r); //save results in r
	printf("H Encode\n");                                                                                                                                                                                                                                                                                                                                            
	showEncode(H_Encode, p, r);

	MultiplyHx(H_Decode, 3, 7, r, s);
	printf("H Decode\n");
	showDecode(H_Decode, r, s);

	r[1] = 1;

	MultiplyHx(H_Decode, 3, 7, r, s);
	printf("H Decode with error introduced\n");
	showDecode(H_Decode, r, s);
	return 0;
}