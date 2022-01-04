#include <stdio.h>
#include "Checksum.h"	

unsigned int Checksum(void* buf, int iBufLen, CHECKSUM iType) { 
	//read the bits in the buffer and divide into chunks
	unsigned char* newBuffer8; // 8 bits
	unsigned short* newBuffer16; //16 bits
	
	int i; //counter to loop through the buffer

	unsigned int sum = 0; //binary addition value
	unsigned int checksum = 0;

	//determine if the checksum is 8 bit or 16 bit
	switch(iType) {
		case CHK_16BIT:
			newBuffer16 = (unsigned short*)buf; //cast to unsigned short, lets us move in 16 bit increments
			//increment through the buffer, using iBufLen

			for (i = 0; i < iBufLen; i++) { 
				sum += *newBuffer16; //reads 16 bits and adds that number in binary to the sum variable

				newBuffer16++; //move the pointer by 16 bits along the buffer, newBuff16 is casted to short
			}
			checksum = sum % (0xFFFF + 0x0001); //want values between 0x0000 to 0xFFFF, so we need to modulas by 0xFFF + 0x1. 0xFFFF = 10000

			return checksum;
			break;

		case CHK_8BIT:
			newBuffer8 = (unsigned char*)buf; //cast to unsigned char, lets us move in 8 bit increments
			//increment through the buffer, using iBufLen
			for (i = 0; i < iBufLen; i++) {
				sum += *newBuffer8; //reads 8 bits and adds that number in binary to the sum variable

				newBuffer8++; //move the pointer by 8 bits along the buffer, newBuff8 is casted to char
			}
			checksum = sum % (0xFF + 0x01); //want values between 0x00 to 0xFF, so we need to modulas by 0xFF + 0x1. 0xFF = 100
			return checksum;
			break;
		default:
			printf("\n Only 8-bit or 16-bit checksums are allowed.\n");
			break;
	}
}