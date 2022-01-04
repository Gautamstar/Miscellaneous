/*
 * Parity.c
 * Description:	Defines the ParityOnBytes() function and 
 * the Parity() function.
 */

#include "Parity.h"

 // lab 1
PARITY ParityOnBytes(char* buff, int buffLen) {
	int i; //counter for my loop
	int counter = 0; //counter to count number of 1s in the array

	for (i = 0; i < buffLen; i++) {
		if (*buff == "1") {
			counter++;
		}
		else if (*buff != '0') {
			return(PAR_ERROR);
		}
		buff++;
	}

	//check if even or odd number of 1s
	if (counter % 2 == 0) {
		printf("Number of ones %i", counter);
		return(PAR_EVEN);
	}
	else {
		printf("Number of ones %i", counter);
		return(PAR_ODD);
	}
} 

PARITY Parity(unsigned char* buff, int buffLen) { //bufflen tracks the amount of chars
	int counter = 0; //counts 1s
	int i; // counts chars for the loop

	unsigned char imask = 0x80; //sets the mask to 8 zeros


	for (i = 0; i < buffLen; i) {
		if (*buff & imask) { //as long as its not 0, increase counter of 1s
			counter++;
		}
		imask >>= 1; //shift to the right by one, until the end 

		if (imask == 0) { //if Imask is all zeros
			imask = 0x80;
			i++; 
			buff++; // buff now points at the next char
		}
	}
	if (counter % 2 == 1) {
		return (PAR_ODD);
	}
	else {
		return(PAR_EVEN);
	}
}