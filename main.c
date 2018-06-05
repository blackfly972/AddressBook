/*
 ============================================================================
 Name        : AddressBook.c
 Author      : Me
 Version     :
 Copyright   : Your copyright notice
 Description : Address Book Program in C
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "address_book.h"

int main(void) {
	setvbuf(stdout, NULL, _IONBF, 0);

	char input[BUFSIZ];

	int done = 0;
	printf("Ready\n");
	while(!done) {

		char command = fgetc(stdin);
		fgetc(stdin);//consume trailing newline
		switch(command) {
		case 'a' : {
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
//			printf("%d\n", desiredIndex); //Test to see if you get the right index that was entered
//			fgetc(stdin);//consume trailing newline
			char* properties = fgets(input, BUFSIZ, stdin);
			properties[strlen(properties) - 1] = '\0';
			addContact(desiredIndex, properties);
			break;
		}
		case 'g' : {
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
		//	fgetc(stdin);//consume trailing newline
			printContact(desiredIndex);
			break;
		}
		case 'd' :{
			int desiredIndex = atoi(fgets(input, BUFSIZ,stdin));
			//fgetc(stdin);//consume trailing newline
			deleteContact(desiredIndex);
			break;
		}
		case 'f' : {
			int desiredIndex = fgetc(stdin) - '0';
			fgetc(stdin);//consume trailing newline
			char* fieldName = fgets(input, BUFSIZ, stdin);
			fieldName[strlen(fieldName) - 1] = '\0';
			printField(desiredIndex, fieldName);
			break;
		}
		case 'l' : {
			char* filename = fgets(input, BUFSIZ, stdin);
			filename[strlen(filename) - 1] = '\0';
			loadContactsFromFile(filename);
			break;
		}
		case 's' : {
			char* filename = fgets(input, BUFSIZ, stdin);
			filename[strlen(filename) - 1] = '\0';
			writeContactsToFile(filename);
			break;
		}
		case 'n' :{
			numberOfContacts();
			break;
		}
		case 'e' :{
			int desiredIndex = fgetc(stdin) - '0';
			fgetc(stdin);//consume trailing newline
			char* fieldName = fgets(input, BUFSIZ, stdin);
			fieldName[strlen(fieldName) - 1] = '\0';
			editContacts(desiredIndex, fieldName);
			break;
		}
		case 'o' :{
			void sortContacts();
			break;
		}
		case 'q' : {
			done = 1;
			break;
		}
		default: {
			break;
		}
		}

	}

	printf("Complete\n");
	return 0;

