/*
* Gautam Singh
* Feb 21, 2021
 * Write a client for crcSlow()
 * Calculate a CRC for a message
 * Introduce a change in the message (simulating an error) and calculate the CRC to see the effect
 * Append the CRC to the message so it is ready for transfer
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crc.h"

#define CRC_SIZE 5

int main() {

	char message[] = "123456789"; //buffer of chars
	int bytes = strlen(message); //lenght of the buffer

	crc compCRC; //type crc for output, crc is an unsigned short

	char crcString[CRC_SIZE]; //string version of the crc, 4 indexes for hex, last index for termination character

	int appendMessageSize = bytes + CRC_SIZE + 3; //hold amount of memory to be freed

	char* appendMessage = (char*)malloc(appendMessageSize * sizeof(char)); // frees up the correct amount of memory for the entire message by multiplying amount of chars by size of a char. Malloc is casted as a char

	for (int i = 0; i < 2; i++) {

		compCRC = crcSlow(message, bytes); //returns the crc of a message

		sprintf_s(crcString, CRC_SIZE, "%x", compCRC); //convert to string

		strcpy_s(appendMessage, appendMessageSize, message); //puts message into appendMessage
		strcat_s(appendMessage, appendMessageSize, " 0x"); //adds a space and 0x to signify hexadecimal
		strcat_s(appendMessage, appendMessageSize, crcString); //combines strings

		printf("\nThe complete transmission is: %s", appendMessage);

		message[2] = '2'; //intrduces a change in the message for the next loop execution.
	}

	return(0);
}